# Example usage:
# If you have testbench/my_test.c, you can execute the following to create a MIPS binary
# make testbench/my_test.mips.bin

# For simulator
DEBUG=0
CC = g++
CPPFLAGS = -W -Wall 
INCFLAGS = -IMIPS-simulator/Memory -IMIPS-simulator/CPU -IMIPS-simulator/Instructions/inc 
#path for finding source files
vpath %.cpp MIPS-simulator:MIPS-simulator/Memory:MIPS-simulator/CPU:MIPS-simulator/Instructions/src
vpath %.s   Testbench/Tests
vpath %.c   Testbench/Tests

# searching for all source files and creating object files names 
SRC_FILES= $(wildcard MIPS-simulator/*/*/*.cpp) $(wildcard MIPS-simulator/*/*.cpp) $(wildcard MIPS-simulator/*.cpp) 
TEST_FILES= $(wildcard Testbench/Tests/*.s) $(wildcard Testbench/Tests/*.c)
ASSEMBLY_TESTS=$(patsubst %.s,%.mips.bin,$(notdir $(TEST_FILES)))
C_TESTS=$(patsubst %.c,%.mips.bin,$(notdir $(TEST_FILES)))
OBJ_FILES=$(patsubst  %.cpp,%.o,$(notdir $(SRC_FILES)))

# For MIPS binaries. Turn on all warnings, enable all optimisations and link everything statically
MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -nostdlib -W -Wall -O0 -fno-builtin -march=mips1 -mfp32 -mplt -mno-check-zero-division
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none 

# Compile C file (.c) into MIPS object file (.o)
%.mips.o: %.c
	@$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Assemble MIPS assembly file (.s) into MIPS object file (.o)
%.mips.o: %.s
	@$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Link MIPS object file (.o), producing .elf, using memory locations specified in spec
%.mips.elf: %.mips.o
	@$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) -T linker.ld $< -o $@

# Extract binary instructions only from linked object file (.elf)
%.mips.bin: %.mips.elf
	@$(MIPS_OBJCOPY) -O binary --only-section=.text $< Testbench/bin/$@

# Disassemble linked object file (.elf), pulling out instructions as MIPS assembly file (.s)
%.mips.s : %.mips.elf
	@$(MIPS_OBJDUMP) -j .text -D $< > $@

#Compile sources into object files and putting them into bin folder
$(OBJ_FILES):%.o:%.cpp bin
ifeq ($(DEBUG),1)
	@$(CC) $(CPPFLAGS)-g $(INCFLAGS) -c $< -o bin/$@
else 
	@$(CC) $(CPPFLAGS) $(INCFLAGS) -c $< -o bin/$@
endif
# rule for bin folder creation
bin: 
	@ mkdir bin

# Build simulator
bin/mips_simulator: $(OBJ_FILES)
	@g++  $(patsubst %.o,bin/%.o, $(OBJ_FILES)) -o bin/mips_simulator
# Dummy for build simulator to conform to spec
simulator: bin/mips_simulator
	@echo Done
# Dummy for build testbench to conform to spec. Could do nothing
testbench:
	@chmod +x bin/*
	@bin/dependency.sh
	@make test
test: $(ASSEMBLY_TESTS) $(C_TESTS)
	echo "Done"
clean:
	@rm bin/*.o
	@rm bin/mips_simulator
