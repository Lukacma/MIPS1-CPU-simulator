#include "I-type.hpp"
#include <bitset>

void parseIType(cpu &cp, uint32_t instruction)
{
  uint32_t immediate = instruction & 0b1111111111111111;            //16 1's
  uint32_t rt = (instruction & 0b111110000000000000000) >> 16;      //5 1's
  uint32_t rs = (instruction & 0b11111000000000000000000000) >> 21; // 5 1's
  uint32_t opcode = (instruction & 0b11111100000000000000000000000000) >> 26;
  switch (opcode)
  {
  case 0b001100:
    ANDI(rs, rt, immediate, cp);
    break;
  case 0b001101:
    ORI(rs, rt, immediate, cp);
    break;
  case 0b001110:
    XORI(rs, rt, immediate, cp);
    break;
  case 0b001010:
    SLTI(rs, rt, immediate, cp);
    break;
  case 0b001011:
    SLTIU(rs, rt, immediate, cp);
    break;
  case 0b001000:
    ADDI(rs, rt, immediate, cp);
    break;
  case 0b001001:
    ADDIU(rs, rt, immediate, cp);
    break;
  case 0b101011:
    SW(rs, rt, immediate, cp);
    break;
  case 0b000100:
    BEQ(rs, rt, immediate, cp);
    break;
  case 0b000001: //opcode is REGIMM
    if (rt == 0b00001 || rt == 0b10001)
    {
      BGEZ(rs, rt, immediate, cp);
    }
    else if (rt == 0b00000 || rt == 0b10000)
    {
      BLTZ(rs, rt, immediate, cp);
    }
    break;
  case 0b000111:
    checkZeroes(16, 20, instruction);
    BGTZ(rs, rt, immediate, cp);
    break;
  case 0b000110:
    checkZeroes(16, 20, instruction);
    BLEZ(rs, rt, immediate, cp);
    break;
  case 0b000101:
    BNE(rs, rt, immediate, cp);
    break;
  case 0b101000:
    SB(rs, rt, immediate, cp);
    break;
  case 0b101001:
    SH(rs, rt, immediate, cp);
    break;
  case 0b100010:
    LWL(rs, rt, immediate, cp);
    break;
  case 0b100110:
    LWR(rs, rt, immediate, cp);
    break;
  case 0b100000:
    LB(rs, rt, immediate, cp);
    break;
  case 0b100100:
    LBU(rs, rt, immediate, cp);
    break;
  case 0b100001:
    LH(rs, rt, immediate, cp);
    break;
  case 0b100101:
    LHU(rs, rt, immediate, cp);
    break;
  case 0b001111:
    checkZeroes(21, 25, instruction);
    LUI(rt, immediate, cp);
    break;
  case 0b100011:
    LW(rs, rt, immediate, cp);
    break;
  default:
    throw Internal_error("Unknown instruction received in function parseIType\n");
  }
}
void SW(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t eff_add = getEffectiveAddress(cp.regRead(rs), immediate);
  if (eff_add & 0b11)
  {
    throw memory_exception("Unaligned address in SW");
  }
  else
  {
    cp.mem.write(eff_add, cp.regRead(rt), false);
  }
}
void SB(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp) //test
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  uint8_t byt = (uint8_t)cp.regRead(rt);
  cp.mem.writeByte(effectiveAddress, byt);
}
void SH(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  if (effectiveAddress & 0b1)
  {
    throw memory_exception("Unaligned address in SH");
  }
  uint8_t bytLS = (uint8_t)cp.regRead(rt);
  uint8_t bytMS = (uint8_t)(cp.regRead(rt) >> 8);
  cp.mem.writeByte(effectiveAddress, bytMS);
  cp.mem.writeByte((effectiveAddress + 1), bytLS);
}
void LUI(uint32_t rt, uint32_t immediate, cpu &cp) //weird name
{
  cp.regWrite(rt, immediate << 16);
}
void LW(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  if (effectiveAddress & 0b11)
  {
    throw memory_exception("Unaligned address in LW");
  }
  uint32_t finalData = loadContainingWord(effectiveAddress, cp);
  cp.regWrite(rt, finalData);
}
void LB(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t modEffectiveAddress = effectiveAddress % 4;
  uint32_t finalData;
  switch (modEffectiveAddress)
  {
  case 0:
    finalData = signExtend32for8((loadedData & 0xFF000000) >> 24);
    break;
  case 1:
    finalData = signExtend32for8((loadedData & 0x00FF0000) >> 16);
    break;
  case 2:
    finalData = signExtend32for8((loadedData & 0x0000FF00) >> 8);
    break;
  case 3:
    finalData = signExtend32for8(loadedData & 0x000000FF);
    break;
  }
  cp.regWrite(rt, finalData);
}
void LBU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t modEffectiveAddress = effectiveAddress % 4;
  uint32_t finalData;
  switch (modEffectiveAddress)
  {
  case 0:
    finalData = (loadedData & 0xFF000000) >> 24;
    break;
  case 1:
    finalData = (loadedData & 0x00FF0000) >> 16;
    break;
  case 2:
    finalData = (loadedData & 0x0000FF00) >> 8;
    break;
  case 3:
    finalData = loadedData & 0x000000FF;
    break;
  }
  cp.regWrite(rt, finalData);
}
void LH(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  if (effectiveAddress % 2 != 0)
  {
    throw memory_exception("Unaligned half-word read in LH");
  }
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t modEffectiveAddress = effectiveAddress % 4;
  uint32_t finalData;
  switch (modEffectiveAddress)
  {
  case 0:
    finalData = signExtend32for16((loadedData & 0xFFFF0000) >> 16);
    break;
  case 2:
    finalData = signExtend32for16(loadedData & 0x0000FFFF);
    break;
  }
  cp.regWrite(rt, finalData);
}
void LHU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  if (effectiveAddress % 2 != 0)
  {
    throw memory_exception("Unaligned half-word read in LH");
  }
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t modEffectiveAddress = effectiveAddress % 4;
  uint32_t finalData;
  switch (modEffectiveAddress) //since we throw an exception if not divisible by two above, 1 and 3 are impossible mod results
  {
  case 0:
    finalData = (loadedData & 0xFFFF0000) >> 16;
    break;
  case 2:
    finalData = loadedData & 0x0000FFFF;
    break;
  }
  cp.regWrite(rt, finalData);
}
void ANDI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  cp.regWrite(rt, cp.regRead(rs) & immediate);
}
void ORI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  cp.regWrite(rt, cp.regRead(rs) | immediate);
}

void XORI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  cp.regWrite(rt, cp.regRead(rs) ^ immediate);
}
void SLTI(uint32_t rs, uint32_t rt, int16_t immediate, cpu &cp)
{
  cp.regWrite(rt, static_cast<int32_t>(cp.regRead(rs)) < immediate);
}
void SLTIU(uint32_t rs, uint32_t rt, int16_t immediate, cpu &cp)
{
  cp.regWrite(rt, cp.regRead(rs) < static_cast<uint32_t>(static_cast<int32_t>(immediate)));
}
void ADDI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  if (addOverflow((int32_t)cp.regRead(rs), (int32_t)signExtend32for16(immediate)))
  {
    throw arithmetic_exception("Signed overflow detected in ADDI");
  }
  uint32_t result = cp.regRead(rs) + signExtend32for16(immediate);
  cp.regWrite(rt, result);
}
void ADDIU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t result = cp.regRead(rs) + signExtend32for16(immediate);
  cp.regWrite(rt, result);
}
void BEQ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  int64_t BDSAddress = (int64_t)cp.getPc(); //pc always points to next instruction when we're in an instruction
  uint32_t regOne = cp.regRead(rs);         //Hohoho boi, we need store those babies since the next instruction may modify the registers!!!
  uint32_t regTwo = cp.regRead(rt);
  execute_next_instruction(cp); //above: need 64 bits since, we cannot interpret MSB of address as sign bit
  if (regOne == regTwo)
  {
    int64_t offset = (int64_t)signExtend64for16(immediate);
    offset = offset << 2;
    int64_t effectiveAddress = BDSAddress + offset;
    cp.setPc((uint32_t)effectiveAddress);
  }
  /*by saving the next instruction address, we give precedence to the first
    branch when we have multiple branches in a row since we simply recurse back up to the first one and
    we use this saved value ignoring the modifications that the others have made to the pc,
    note that a branch doesn't run the next instruction, it simply changes the PC and so the inner branches can
    only run their next instruction but modifying the pc is irrelevant*/
} /*Effectively, when BEQ's are executed on subsequent lines, the subsequent ones have all their test conditions fail and no branch is performed
this makes sense since otherwise we need to determine when the scope of a branch ends and we recurse back to an outer branch which makes no sense*/
void BNE(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  int64_t BDSAddress = (int64_t)cp.getPc();
  uint32_t regOne = cp.regRead(rs);
  uint32_t regTwo = cp.regRead(rt);
  execute_next_instruction(cp);
  if (regOne != regTwo)
  {
    int64_t offset = (int64_t)signExtend64for16(immediate);
    offset = offset << 2;
    int64_t effectiveAddress = BDSAddress + offset;
    cp.setPc((uint32_t)effectiveAddress);
  }
}
void BGEZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  if (rt == 0b10001)
  {
    cp.regWrite(31, (cp.getPc() + 4));
  }
  int64_t BDSAddress = (int64_t)cp.getPc();
  uint32_t reg = cp.regRead(rs);
  execute_next_instruction(cp);
  if (!(reg & 0x80000000))
  {
    int64_t offset = (int64_t)signExtend64for16(immediate);
    offset = offset << 2;
    int64_t effectiveAddress = BDSAddress + offset;
    cp.setPc((uint32_t)effectiveAddress);
  }
}
void BGTZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  int64_t BDSAddress = (int64_t)cp.getPc();
  uint32_t reg = cp.regRead(rs);
  execute_next_instruction(cp);
  if (!(reg & 0x80000000) && (reg != 0))
  {
    int64_t offset = (int64_t)signExtend64for16(immediate);
    offset = offset << 2;
    int64_t effectiveAddress = BDSAddress + offset;
    cp.setPc((uint32_t)effectiveAddress);
  }
}
void BLEZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{ //make sure to check for zeroes
  int64_t BDSAddress = (int64_t)cp.getPc();
  uint32_t reg = cp.regRead(rs);
  execute_next_instruction(cp);
  if ((reg & 0x80000000) || reg == 0)
  {
    int64_t offset = (int64_t)signExtend64for16(immediate);
    offset = offset << 2;
    int64_t effectiveAddress = BDSAddress + offset;
    cp.setPc((uint32_t)effectiveAddress);
  }
}
void BLTZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  if (rt == 0b10000)
  {
    cp.regWrite(31, (cp.getPc() + 4)); //linking make sure this happens regardless of whether we branch
  }
  int64_t BDSAddress = (int64_t)cp.getPc();
  //std::cerr << "address without casting " << std::bitset<32>(cp.getPc()) << "\n";
  //std::cerr << "BDS address " << std::bitset<64>(BDSAddress) << "\n";
  uint32_t reg = cp.regRead(rs);
  execute_next_instruction(cp);
  if (reg & 0x80000000)
  {
    int64_t offset = (int64_t)(signExtend64for16(immediate));
    offset = offset << 2;
    // std::cerr << "Offset " << std::bitset<64>(offset) << "\n";
    int64_t effectiveAddress = BDSAddress + offset;
    //std::cerr << "Effective address " << std::bitset<32>(effectiveAddress) << "\n";
    cp.setPc((uint32_t)effectiveAddress);
  }
}
void LWL(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  int numBytesToLoad = 4 - ((int)(effectiveAddress % 4));
  //std::cerr << "LWL Bytes to load " << numBytesToLoad << "\n";
  uint32_t registerDataInitial = cp.regRead(rt);
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t registerDataFinal;
  switch (numBytesToLoad)
  {
  case 1:
    registerDataFinal = (registerDataInitial & 0x00FFFFFF) | ((loadedData & 0x000000FF) << 24);
    break;
  case 2:
    registerDataFinal = (registerDataInitial & 0x0000FFFF) | ((loadedData & 0x0000FFFF) << 16);
    break;
  case 3:
    registerDataFinal = (registerDataInitial & 0x000000FF) | ((loadedData & 0x00FFFFFF) << 8);
    break;
  case 4:
    registerDataFinal = loadedData;
    break;
  }
  cp.regWrite(rt, registerDataFinal);
}
void LWR(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp)
{
  uint32_t effectiveAddress = getEffectiveAddress(cp.regRead(rs), immediate);
  uint32_t numBytesToLoad = effectiveAddress % 4 + 1; //loaded from LS this needs to be unsigned since modulo is sign-sensitive
  //std::cerr << "LWR Bytes to load " << numBytesToLoad << "\n";
  uint32_t registerDataInitial = cp.regRead(rt);
  uint32_t loadedData = loadContainingWord(effectiveAddress, cp);
  uint32_t registerDataFinal;
  switch (numBytesToLoad)
  {
  case 1:
    registerDataFinal = (registerDataInitial & 0xFFFFFF00) | ((loadedData & 0xFF000000) >> 24);
    break;
  case 2:
    registerDataFinal = (registerDataInitial & 0xFFFF0000) | ((loadedData & 0xFFFF0000) >> 16);
    break;
  case 3:
    registerDataFinal = (registerDataInitial & 0xFF000000) | ((loadedData & 0xFFFFFF00) >> 8);
    break;
  case 4:
    registerDataFinal = loadedData;
    break;
  }
  cp.regWrite(rt, registerDataFinal);
}
uint32_t signExtend32for16(uint32_t val)
{
  if (val & 0x8000)
  {
    val = val | 0xFFFF0000;
  }
  return val;
}
uint64_t signExtend64for16(uint32_t val)
{
  uint64_t valExtended = (uint64_t)val;
  if (val & 0x8000)
  {
    valExtended = valExtended | 0xFFFFFFFFFFFF0000;
  }
  return valExtended;
}
uint32_t getEffectiveAddress(uint32_t base, uint32_t immediate)
{
  uint32_t offset = signExtend32for16(immediate);
  return (base + offset);
}
bool addressIsReadable(uint32_t address)
{
  if ((address >= 0x20000000 && address < 0x24000000) || (address >= 0x10000000 && address < 0x11000000) || (address == 0x30000000))
  {
    return true;
  }
  else
  {
    return false;
  }
}
uint32_t loadContainingWord(uint32_t effectiveAddress, cpu &cp)
{
  uint32_t loadedData;
  int32_t containingWordAddress = effectiveAddress - effectiveAddress % 4; //the aligned address of the word from which we extract the relevant bytes
  if (addressIsReadable((uint32_t)containingWordAddress))
  {
    cp.mem.readUnrestricted(containingWordAddress, loadedData);
  }
  else
  {
    throw memory_exception("Address out of bounds on a read\n");
  }
  return loadedData;
}
uint32_t signExtend32for8(uint32_t val)
{
  if (val & 0x80)
  {
    val = val | 0xFFFFFF00;
  }
  return val;
}
/*bool addOverflow(int32_t valA, int32_t valB){
  int32_t temp = valA + valB;
	if (valA < 0 && valB < 0){
			if(temp > 0){
				return true;
			}
	}else if(valA > 0 && valB >0){
			if(temp < 0){
				return true;
			}
	}
	return false;
}*/
