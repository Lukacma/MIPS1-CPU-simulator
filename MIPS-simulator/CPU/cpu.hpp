#ifndef CPU_H
#define CPU_H
#include "memory.hpp"
class cpu
{
public:
  cpu(memory &mem);
  void regWrite(int regIndex, uint32_t in_data);
  uint32_t regRead(int regIndex);
  void setPc(uint32_t val);
  uint32_t getPc();
  void setHI(uint32_t val);
  void setLO(uint32_t val);
  uint32_t getHI();
  uint32_t getLO();
  memory mem;

private:
  uint32_t regs[32];
  uint32_t pc;
  uint32_t HI;
  uint32_t LO;
};
#endif
