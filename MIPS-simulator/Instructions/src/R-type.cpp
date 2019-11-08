#include "R-type.hpp"
#include <bitset>
#include <cmath>
void parseRType(cpu &cp, uint32_t instruction)
{
    uint32_t funct = (instruction & 0b111111);
    uint32_t shamt = (instruction & 0b11111000000) >> 6;
    uint32_t rd = (instruction & 0b1111100000000000) >> 11;
    uint32_t rt = (instruction & 0b111110000000000000000) >> 16;
    uint32_t rs = (instruction & 0b11111000000000000000000000) >> 21;
    switch (funct)
    {
    case 0b100101: //OR operation
        check0Shift(shamt);
        OR(cp, rd, rt, rs);
        break;

    case 0b100110:
        check0Shift(shamt);
        XOR(cp, rd, rt, rs);
        break;
    case 0b101011:
        check0Shift(shamt);
        SLTU(cp, rd, rt, rs);
        break;
    case 0b101010:
        check0Shift(shamt);
        SLT(cp, rd, rt, rs);
        break;
    case 0b000000:
        if (rs != 0)
            throw invalid_instruction("In function parseRType: rs=0 expected");
        SLL(cp, rd, rt, shamt);
        break;
    case 0b000100:
        check0Shift(shamt);
        SLLV(cp, rd, rt, rs);
        break;
    case 0b001000:
        checkZeroes(6, 20, instruction);
        execute_next_instruction(cp);
        JR(cp, rs);
        break;
    case 0b011000:
        checkZeroes(6, 15, instruction);
        MULT(cp, rt, rs);
        break;
    case 0b011001:
        checkZeroes(6, 15, instruction);
        MULTU(cp, rt, rs);
        break;
    case 0b010000:
        checkZeroes(6, 10, instruction);
        checkZeroes(16, 25, instruction);
        MFHI(cp, rd);
        break;
    case 0b010010:
        checkZeroes(6, 10, instruction);
        checkZeroes(16, 25, instruction);
        MFLO(cp, rd);
        break;
    case 0b010001:
        checkZeroes(6, 20, instruction);
        MTHI(cp, rs);
        break;
    case 0b010011:
        checkZeroes(6, 20, instruction);
        MTLO(cp, rs);
        break;
    case 0b000011:
        checkZeroes(7, 11, instruction);
        SRA(cp, rd, rt, shamt);
        break;
    case 0b000111:
        check0Shift(shamt);
        SRAV(cp, rd, rt, rs);
        break;
    case 0b000010:
        checkZeroes(7, 11, instruction);
        SRL(cp, rd, rt, shamt);
        break;
    case 0b000110:
        check0Shift(shamt);
        SRLV(cp, rd, rt, rs);
        break;
    case 0b100011:
        check0Shift(shamt);
        SUBU(cp, rd, rt, rs);
        break;
    case 0b100010:
        check0Shift(shamt);
        SUB(cp, rd, rt, rs);
        break;
    case 0b100000:
        checkZeroes(6,10, instruction);
        ADD(cp, rd , rt, rs);
        break;
    case 0b100001:
        checkZeroes(6,10,instruction);
        ADDU(cp, rd , rt, rs);
        break;
    default:
        throw Internal_error("Unknown instruction received in function parseRType\n");
    }
}

void OR(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rt) | cp.regRead(rs));
}

void XOR(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rt) ^ cp.regRead(rs));
}
void SLTU(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rs) < cp.regRead(rt));
}

void SLT(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, static_cast<int32_t>(cp.regRead(rs)) < static_cast<int32_t>(cp.regRead(rt)));
}

void SLL(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt)
{
    cp.regWrite(rd, cp.regRead(rt) << shamt);
}
void SLLV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rt) << (cp.regRead(rs) & 0b11111));
}

void SRA(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt)
{
    cp.regWrite(rd, static_cast<int32_t>(cp.regRead(rt)) >> shamt);
}
void SRAV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, static_cast<int32_t>(cp.regRead(rt)) >> (cp.regRead(rs) & 0b11111));
}
void SRL(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt)
{
    cp.regWrite(rd, cp.regRead(rt) >> shamt);
}
void SRLV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rt) >> (cp.regRead(rs) & 0b11111));
}
void SUBU(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    cp.regWrite(rd, cp.regRead(rs) - cp.regRead(rt));
}
void SUB(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs)
{
    int32_t result = static_cast<int32_t>(cp.regRead(rs)) - static_cast<int32_t>(cp.regRead(rt));
    if ((rs > rt && result < 0) && (rs < rt && result > 0))
        throw arithmetic_exception("In function SUB: overflow detected");

    cp.regWrite(rd, result);
}
void ADD(cpu& cp, uint32_t rd, uint32_t rt, uint32_t rs){
  int32_t valT = (int32_t)cp.regRead(rt);
  int32_t valS = (int32_t)cp.regRead(rs);
  if(addOverflow(valT, valS)){//the reason we cast is for the comparisons to work in c but addition is same
    throw arithmetic_exception("Signed overflow detected in ADD");
  }
  int32_t result = valT + valS;
  cp.regWrite(rd, (uint32_t)result);
}
void ADDU(cpu& cp, uint32_t rd, uint32_t rt, uint32_t rs){
  uint32_t valT = cp.regRead(rt);
  uint32_t valS = cp.regRead(rs);
  uint32_t result = valT + valS;
  cp.regWrite(rd,result);
}
void check0Shift(uint32_t shamt)
{
    if (shamt != 0)

        throw invalid_instruction("In function parseRtype: 0 shift expected");
}
void JR(cpu &cp, uint32_t rs)
{
    uint32_t targetAddress = cp.regRead(rs);
    {
        if (targetAddress & 0b11)
        {
            throw memory_exception("Unaligned address in JR");
        }
        else
        {
            cp.setPc(targetAddress);
        }
    }
}
void MULT(cpu &cp, uint32_t rt, uint32_t rs)
{
    int64_t valOne = signExtend64(cp.regRead(rt)); //NOTE:casting does not sign-extend
    int64_t valTwo = signExtend64(cp.regRead(rs));
    int64_t result = valOne * valTwo;
    cp.setHI((uint32_t)(result >> 32));
    cp.setLO((uint32_t)(result & 0xFFFFFFFF));
}
void MULTU(cpu &cp, uint32_t rt, uint32_t rs)
{
    int64_t valOne = (int64_t)cp.regRead(rt);
    int64_t valTwo = (int64_t)cp.regRead(rs);
    int64_t result = valOne * valTwo;
    cp.setHI((uint32_t)(result >> 32));
    cp.setLO((uint32_t)(result & 0xFFFFFFFF));
}
void MFHI(cpu &cp, uint32_t rd)
{
    cp.regWrite(rd, cp.getHI());
}
void MFLO(cpu &cp, uint32_t rd)
{
    cp.regWrite(rd, cp.getLO());
}
void MTHI(cpu &cp, uint32_t rs)
{
    cp.setHI(cp.regRead(rs));
}
void MTLO(cpu &cp, uint32_t rs)
{
    cp.setLO(cp.regRead(rs));
}
void checkZeroes(int startIndex, int endIndex, uint32_t instruction)
{

    /*checks that all bits between startIndex and endIdex are 0,
   inclusive of startIndex and endIndex so to check
   if only 1 bit is zero start and endIndex need to be the same*/

    uint32_t mask = 1;
    for (int i = startIndex; i <= endIndex; i++)
    {

        if (instruction & (mask << i))
        {
            throw invalid_instruction("Invalid instruction in parseRType");
        }
    }
}
int64_t signExtend64(uint32_t in)
{
    int64_t result = (int64_t)in;
    if (result & 0x80000000)
    {
        result = result | 0xFFFFFFFF00000000;
    }
    return result;
}
bool addOverflow(int32_t valA, int32_t valB){
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
}
