#include "J-type.hpp"
#include <string>
#include "errors.hpp"

void parseJType(cpu &cp, uint32_t instruction)
{
    uint32_t jaddress = instruction & 0b11111111111111111111111111;
    uint32_t opCode = instruction >> 26;
    switch (opCode)
    {
    case 2:
        // J(cp, jaddress);
        break;
    case 3:
        // JAL(cp, jaddress);
        break;
    default:
        throw Internal_error("Unknown instruction received in function parseJType\n");
    }
}
