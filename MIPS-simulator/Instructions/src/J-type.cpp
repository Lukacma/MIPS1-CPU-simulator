#include "J-type.hpp"
#include <string>
#include "errors.hpp"

void parseJType(cpu &cp, uint32_t instruction)
{
    uint32_t jAddress = instruction & 0b11111111111111111111111111;
    uint32_t opCode = instruction >> 26;
    switch (opCode)
    {
    case 2:
        J(cp, jAddress);
        break;
    case 3:
        JAL(cp, jAddress);
        break;
    default:
        throw Internal_error("Unknown instruction received in function parseJType\n");
    }
}
void J(cpu& cp, uint32_t jAddress)
{
    uint32_t region = cp.getPc()&0xF0000000;
    uint32_t targetAddress = region | (jAddress << 2);
    execute_next_instruction(cp);
    cp.setPc(targetAddress);
}
void JAL(cpu& cp, uint32_t jAddress){
    cp.regWrite(31, (cp.getPc() + 4));//link
    uint32_t region = cp.getPc()&0xF0000000;
    uint32_t targetAddress = region | (jAddress << 2);
    execute_next_instruction(cp);
    cp.setPc(targetAddress);
}
