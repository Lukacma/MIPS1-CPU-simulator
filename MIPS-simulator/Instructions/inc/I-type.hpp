#ifndef I_TYPE_HPP
#define I_TYPE_HPP
#include "cpu.hpp"
#include "R-type.hpp"
void parseIType(cpu &cp, uint32_t instruction);
/* parse I-type instruction and executes it.
Input: cp: handler for memory and registers.
       instruction: R-type binary instruction to be executed.*/
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
uint32_t signExtend32(uint32_t val);
//bool addOverflow(int32_t valA, int32_t valB);
#endif // !I_TYPE_HPP
