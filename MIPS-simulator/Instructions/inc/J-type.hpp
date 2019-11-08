#ifndef J_TYPE_HPP
#define J_TYPE_HPP
#include "cpu.hpp"

void parseJType(cpu &cp, uint32_t instruction);
/* parse J-type instruction and executes it.
Input: cp: handler for memory and registers.
       instruction: R-type binary instruction to be executed.*/

#endif // !J_TYPE_HPP
