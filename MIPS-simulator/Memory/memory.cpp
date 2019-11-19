#include <iostream>
#include <bitset>
#include "memory.hpp"
#include "errors.hpp"
memory::memory()
{
  length = 0x30000008;
  data = (uint8_t *)calloc(length, 1); //calloc zeroes out the memory that it allocates, not necessaryfor the entire range but a loop for just the read-write area would be ugly
};                                     //1 is the size of a block 1 byte needed here.
void memory::write(uint32_t address, uint32_t in_data, bool isPriveleged)
{
  if ((address >= 0x20000000 && address < 0x24000000) && !isPriveleged)
  {
    data[address] = (uint8_t)(in_data >> 24);
    data[address + 1] = (uint8_t)((in_data & 0x00FF0000) >> 16);
    data[address + 2] = (uint8_t)((in_data & 0x0000FF00) >> 8);
    data[address + 3] = (uint8_t)(in_data & 0x000000FF);
  }
  else if (address >= 0x30000004 && address <= 0x30000007)
  {
    uint32_t output;
    if (address == 0x30000004)
    {
      //std::cout << std::bitset<32>(in_data>>24);
      output = (in_data & 0xFF);
    }
    else
    {
      output = 0;
    }
    std::putchar(output);
    if (std::ferror(stdout))
    {
      std::cerr << "IO exception when writing to stdout in mem.write()";
      std::exit(-21);
    }
  } //consider priveleges
  else if ((address >= 0x10000000 && address < 0x11000000) && isPriveleged)
  { //for potential internal testing, normal execution will never write to instruction memory.
    data[address] = (uint8_t)(in_data >> 24);
    data[address + 1] = (uint8_t)((in_data & 0x00FF0000) >> 16);
    data[address + 2] = (uint8_t)((in_data & 0x0000FF00) >> 8);
    data[address + 3] = (uint8_t)(in_data & 0x000000FF);
  }
  else
  {
    throw memory_exception("Address out of bounds on a write\n");
  }
};
void memory::writeByte(uint32_t address, uint8_t in_data)
{
  if ((address >= 0x20000000 && address < 0x24000000))
  {
    data[address] = in_data;
  }
  else if (address >= 0x30000004 && address <= 0x30000007)
  {
    uint32_t output;
    if (address == 0x30000004)
    {
      //std::cout << std::bitset<32>(in_data>>24);
      output = (in_data);
    }
    else
    {
      output = 0;
    }
    std::putchar(output);
    if (std::ferror(stdout))
    {
      std::cerr << "IO exception when writing to stdout in mem.writeByte()"; //no idea when the hell this will happen butcha gotta follow the spec
      std::exit(-21);
    }
  }
  else
  {
    throw memory_exception("Address out of bounds on a byte write\n");
  }
}
void memory::read(uint32_t address, uint32_t &out_data, bool isPriveleged) const
{
  if ((address >= 0x20000000 && address < 0x24000000) && !isPriveleged)
  {                                                                                                                                                      //just for quick testing, too lazy to add a test f
    out_data = ((uint32_t)data[address]) << 24 | ((uint32_t)data[address + 1]) << 16 | ((uint32_t)data[address + 2]) << 8 | (uint32_t)data[address + 3]; //add boundary checks for priveleged mode
  }
  else if (address >= 0x30000000 && address <= 0x30000003 && !isPriveleged)
  {
    uint32_t temp;
    temp = std::getchar();
    if (temp == static_cast<uint32_t>(EOF))
    {
      out_data = 0xFFFFFFFF;
    }
    else
    {
      out_data = temp;
    }
  }
  else if ((address >= 0x10000000 && address < 0x11000000) && isPriveleged)
  {
    out_data = ((uint32_t)data[address]) << 24 | ((uint32_t)data[address + 1]) << 16 | ((uint32_t)data[address + 2]) << 8 | (uint32_t)data[address + 3];
  }
  else
  {
    throw memory_exception("Address out of bounds on a read\n"); //leaving lack of alignment to the CPU to handle
  }
};
void memory::readByte(uint32_t address, uint8_t &out_data)
{
  if ((address >= 0x20000000 && address < 0x24000000) || (address >= 0x10000000 && address < 0x11000000)) //we can read from instruction memory as well
  {
    out_data = data[address];
  }
  else
  {
    throw memory_exception("Address out of bounds on a read\n");
  } //what about read bytes from input memory.
}
void memory::readUnrestricted(uint32_t address, uint32_t &out_data)
{
  out_data = ((uint32_t)data[address]) << 24 | ((uint32_t)data[address + 1]) << 16 | ((uint32_t)data[address + 2]) << 8 | (uint32_t)data[address + 3];
  // std::cout << "data read: " << (int)data[address + 2] << "  " << (int)data[address + 3] << "  " << std::endl;

  if (address == 0x30000000)
  {
    char temp;
    temp = std::getchar();
    if (temp == EOF)
    {
      out_data = 0xFFFFFFFF;
    }
    else
    {
      out_data = (uint32_t)temp;
    }
  }
}
void memory::loadBin(uint8_t *binP, int binSize)
{ //add case for when the binary cannot fit into the instruction memory ignore that for now
  if (binSize > 0x1000000)
  {
    throw memory_exception("binary file bigger than instruction memory");
  }
  uint8_t *memP = data + 0x10000000;
  for (int i = 0; i < binSize; i++)
  {
    *memP++ = *binP++; //note that binP is passed by value so safe to increment here
  }
};
