#include <iostream>
#include <fstream>
#include <bitset>
#include "memory.hpp"
#include "cpu.hpp"
#include "errors.hpp"
#include "R-type.hpp"
#include "J-type.hpp"
#include "I-type.hpp"
uint32_t parseInstruction(int pc, const memory &mem);
uint8_t getExitCode(cpu cp);
void loadBinary(memory &mem, std::string fileName);

int main(int argc, char *argv[])
{
	memory mem;
	//register initialisation
	cpu cp(mem); //assigning the memory to the cpu
	if (argv[1] == NULL)
	{
		std::cerr << "LOL, me no run when u no give filename \n";
		std::exit(-21);
	}
	std::string fileName = argv[1];
	try
	{
		loadBinary(cp.mem, fileName);
	}
	catch (const IO_error &e)
	{
		std::cerr << e.what();
		std::exit(-21);
	}

	try
	{
		//Execution
		while (cp.getPc() != 0)
		{
			execute_next_instruction(cp);
		}
	}
	catch (const invalid_instruction &e)
	{
		std::cerr << e.what();
		std::exit(-12);
	}
	catch (const arithmetic_exception &e)
	{
		std::cerr << e.what();
		std::exit(-10);
	}
	catch (const memory_exception &e)
	{
		std::cerr << e.what();
		std::exit(-11);
	}
	catch (const Internal_error &e)
	{
		std::cerr << e.what();
		std::exit(-20);
	}
	catch (const IO_error &e)
	{
		std::cerr << e.what();
		std::exit(-21);
	}

	std::exit(getExitCode(cp));
};
void execute_next_instruction(cpu &cp)
{
	uint32_t instruction = parseInstruction(cp.getPc(), cp.mem);
	cp.setPc(cp.getPc() + 4); //moving pc to next instruction
	int opCode = instruction >> 26;
	if (opCode == 0)
	{
		parseRType(cp, instruction);
	}
	else if (opCode == 2 || opCode == 3)
	{ //j-type
		parseJType(cp, instruction);
	}
	else
	{ //i-type
		parseIType(cp, instruction);
	}
};
uint32_t parseInstruction(int pc, const memory &mem)
{ //uses the program counter to read the instruction from the memory
	uint32_t instruction;
	mem.read(pc, instruction, true);
	return instruction;
};
uint8_t getExitCode(cpu cp)
{
	uint32_t regVal = cp.regRead(2);
	uint8_t exitCode = (uint8_t)(regVal & 0x000000FF);
	return exitCode;
};
void loadBinary(memory &mem, std::string fileName)
{ //loads the binary file that
	int size;
	char *binP;
	std::ifstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		size = file.tellg();
		file.seekg(0, file.beg);
		//std::cout << "size " << size << "\n";
		binP = new char[size];
		file.read(binP, size);
		mem.loadBin((uint8_t *)binP, size);
		delete[] binP; //deallocate the temporary memory
		file.close();
	}
	else
	{
		throw IO_error("Binary file:" + fileName + "not found \n");
	}
};
