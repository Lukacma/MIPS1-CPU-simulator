#ifndef I_TYPE_HPP
#define I_TYPE_HPP
#include "cpu.hpp"
#include "R-type.hpp"
void parseIType(cpu &cp, uint32_t instruction);
/* parse I-type instruction and executes it.
Input: cp: handler for memory and registers.
       instruction: R-type binary instruction to be executed.*/
void ANDI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void ORI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
/* bitwise OR on  source register rs and immediate stored in rt.
   Input: rt: index of destination register
          rs: index of first source register
          immediate: 16 bit constant 0 extended to 32
          cp: handler for memory and registers */
void XORI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
/* bitwise exclusive OR on  source register rs and immediate stored in rt.
   Input: rt: index of destination register
          rs: index of first source register
          immediate: 16 bit constant 0 extended to 32
          cp: handler for memory and registers */
void SLTI(uint32_t rs, uint32_t rt, int16_t immediate, cpu &cp);
/* If signed(rs)<signed(immmediate) rt will be 1. Otherwise 0.
     Input: rt: index of destination register
            rs: index of first source register
            immediate: 16 bit signed constant
            cp: handler for memory and register*/
void SLTIU(uint32_t rs, uint32_t rt, int16_t immediate, cpu &cp);
/* If unsigned(rs)<unsigned(immmediate) rt will be 1. Otherwise 0.
Immediate is signed extended to 32 bits before comparison.
     Input: rt: index of destination register
            rs: index of first source register
            immediate: 16 bit signed constant
            cp: handler for memory and register*/
void ADDI(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void ADDIU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
uint32_t signExtend32for16(uint32_t val);
void LWR(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LWL(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
uint64_t signExtend64for16(uint32_t val);
//bool addOverflow(int32_t valA, int32_t valB);
void SW(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
/* SW value of rt into effective address. This address is evaluated by adding  value of immediate to value int rs.
     Input: rt: index of destination register
            rs: index of first source register
            immediate: 16 bit signed constant
            cp: handler for memory and register*/
void SH(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void SB(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LB(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LBU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LH(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LHU(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void LUI(uint32_t rt, uint32_t immediate, cpu &cp);
void LW(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void BEQ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void BGEZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);//implements both BGEZ and BGEZALL due to them sharing an opcode and using rt to distinguish between them
void BGTZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void BLEZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);
void BLTZ(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);//implements both BLTZ and BLTZALL for same reason as above
void BNE(uint32_t rs, uint32_t rt, uint32_t immediate, cpu &cp);

uint32_t getEffectiveAddress(uint32_t base, uint32_t immediate);
bool addressIsReadable(uint32_t address);
uint32_t loadContainingWord(uint32_t effectiveAddress, cpu& cp);
uint32_t signExtend32for8(uint32_t val);
#endif // !I_TYPE_HPP
