#include "cpu.hpp"
cpu::cpu(memory &in_mem)
{
  pc = 0x10000000;
  for (int i = 0; i < 32; i++)
  {
    regs[i] = 0;
  }
  HI = 0;
  LO = 0;
  mem = in_mem;
}
void cpu::setHI(uint32_t val)
{
  HI = val;
}
void cpu::setLO(uint32_t val)
{
  LO = val;
}
uint32_t cpu::getHI()
{
    return HI;
}
uint32_t cpu::getLO()
{
    return LO;
}
void cpu::regWrite(int regIndex, uint32_t in_data)
{
  if (regIndex > 0 && regIndex <= 31)
  {
    regs[regIndex] = in_data;
  }
  else if(regIndex == 0)
  {
    //do nothing
  }
  else
  {
    throw invalid_instruction("In function regWrite: register index out of bounds");
  }
}

uint32_t cpu::regRead(int regIndex)
{
  if (regIndex >= 0 && regIndex <= 31)
  {
    return regs[regIndex];
  }
  else
  {
    throw invalid_instruction("In function regRead: register index out of bounds");
  }
}
void cpu::setPc(uint32_t val)
{
  pc = val;
}
uint32_t cpu::getPc()
{
  return pc;
}
