#ifndef R_TYPE_HPP
#define R_TYPE_HPP
#include "cpu.hpp"

//void ADDU(cpu& cp, uint32_t srcA, uint32_t srcB, uint32_t dest);Not implemented yet
void ADD(cpu& cp, uint32_t rd, uint32_t rt, uint32_t rs);
void ADDU(cpu& cp, uint32_t rd, uint32_t rt, uint32_t rs);
bool addOverflow(int32_t valA, int32_t valB);//returns true for signed overflow on the two 32-bit signed ints it gets
void execute_next_instruction(cpu &cp);
/* this function is defined in simulator.cpp. Its header is here to avoid creating header file for simulator.cpp file */
void OR(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
void checkZeroes(int startIndex, int endIndex, uint32_t instruction);
void parseRType(cpu &cp, uint32_t instruction); /* parse R-type instruction and executes it.
Input: cp: handler for memory and registers.
       instruction: R-type binary instruction to be executed.*/
void JR(cpu &cp, uint32_t rs);
void MULT(cpu &cp, uint32_t rt, uint32_t rs);
void MULTU(cpu &cp, uint32_t rt, uint32_t rs);
void MFHI(cpu &cp, uint32_t rd);
void MFLO(cpu &cp, uint32_t rd);
void MTHI(cpu &cp, uint32_t rs);
void MTLO(cpu &cp, uint32_t rs);
/*
Treats the two register values as signed and multiplies them, placing the 64 bit result in the LO and HI registers. No exceptions will ever be thrown.
NOTE: "If either of the two preceding instructions is MFHI or MFLO, the result of the MFHI or
MFLO is undefined. Reads of the HI or LO special registers must be separated from
subsequent instructions that write to them by two or more other instructions." Not sure if we should check for this
I guess undefined means don't care so no*/
int64_t signExtend64(uint32_t in);

void checkZeroes(int startIndex, int endIndex, uint32_t instruction);
void JR(cpu &cp, uint32_t rs);
void OR(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/* bitwise OR on both source register stored in rd.
   Input: rd: index of destination register
          rt: index of first source register
          rs: index of second source register.
          cp: handler for memory and registers */
void XOR(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/* bitwise exclusive OR on both source register stored in rd.
   Input: rd: index of destination register
          rt: index of first source register
          rs: index of second source register.
          cp: handler for memory and registers */
void check0Shift(uint32_t shamt);
/* check if shamt==0 and throws invalid_instruction exception if not.*/
void SLTU(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/* Compare the contents of GPR rs and GPR rt as unsigned integers and record the
Boolean result of the comparison in GPR rd. rd<-- rs<rt
Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register.
          cp: handler for memory and registers
*/
void SLT(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/* Compare the contents of GPR rs and GPR rt as signed integers and record the
Boolean result of the comparison in GPR rd. rd<-- rs<rt
Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register.
          cp: handler for memory and registers
*/
void SLL(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt);
/*The contents of the low-order 32-bit word of GPR rt are shifted left, inserting zeroes
into the emptied bits; the word result is placed in GPR rd. The shift amount comes from shamt.
Input:    rd: index of destination register
          rt: index of first source register
          shamt: shift amount
          cp: handler for memory and registers*/
void SLLV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/*The contents of the low-order 32-bit word of GPR rt are shifted left, inserting zeroes
into the emptied bits; the word result is placed in GPR rd. The shift amount comes from lowest 5 bits of rs.
Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register
          cp: handler for memory and registers*/
void SRA(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt);
/* The contents of rt are arithmetically shifted by "shamt" places.
   The result is stored in rd.
   Input:  rd: index of destination register
          rt: index of first source register
          shamt: shift amount
          cp: handler for memory and registers*/
void SRAV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/*The contents of rt are shifted right arithmetically. Result is placed in rd. The shift amount comes from lowest 5 bits of rs.
Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register
          cp: handler for memory and registers*/
void SRL(cpu &cp, uint32_t rd, uint32_t rt, uint32_t shamt);
/* The contents of rt are logically shifted by "shamt" places.
   The result is stored in rd.
   Input:  rd: index of destination register
          rt: index of first source register
          shamt: shift amount
          cp: handler for memory and registers*/
void SRLV(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/*The contents of rt are shifted right logically. Result is placed in rd. The shift amount comes from lowest 5 bits of rs.
Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register
          cp: handler for memory and registers*/
void SUBU(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/*The 32-bit word value in  rt is subtracted from the 32-bit value in rs and stored in rd. No overflow is captured
    Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register
          cp: handler for memory and registers*/
void SUB(cpu &cp, uint32_t rd, uint32_t rt, uint32_t rs);
/*The 32-bit word value in  rt is subtracted from the 32-bit value in rs and stored in rd. Arithmetic overflow captured.
    Input:    rd: index of destination register
          rt: index of first source register
          rs: index of second source register
          cp: handler for memory and registers*/

#endif // !R_TYPE.HPP
