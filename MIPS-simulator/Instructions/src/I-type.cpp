#include "I-type.hpp"

void parseIType(cpu &cp, uint32_t instruction)
{
    uint32_t immediate = instruction & 0b1111111111111111;            //16 1's
    uint32_t rt = (instruction & 0b111110000000000000000) >> 16;      //5 1's
    uint32_t rs = (instruction & 0b11111000000000000000000000) >> 21; // 5 1's
    uint32_t opcode = (instruction & 0b11111100000000000000000000000000) >> 26;
    switch (opcode)
    {
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
    default:
        throw Internal_error("Unknown instruction received in function parseIType\n");
    }
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
void ADDI(uint32_t rs, uint32_t rt, uint32_t immediate,cpu& cp){
  if(addOverflow((int32_t)cp.regRead(rs), (int32_t)signExtend32(immediate))){
      throw arithmetic_exception("Signed overflow detected in ADDI");
  }
  uint32_t result = cp.regRead(rs) + signExtend32(immediate);
  cp.regWrite(rt, result);
}
void ADDIU(uint32_t rs, uint32_t rt, uint32_t immediate,cpu& cp){
  uint32_t result = cp.regRead(rs) + signExtend32(immediate);
  cp.regWrite(rt, result);
}
uint32_t signExtend32(uint32_t val)
{
    if (val & 0x8000)
    {
        val = val | 0xFFFF0000;
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
