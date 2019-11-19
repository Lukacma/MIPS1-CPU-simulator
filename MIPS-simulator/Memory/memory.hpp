#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "errors.hpp"
#include <iostream>
class memory
{
private:
  uint length;
  uint8_t *data;

public:
  memory();
  void loadBin(uint8_t *binP, int binSize);
  void write(uint32_t address, uint32_t in_data, bool isPriveleged);
  void read(uint32_t address, uint32_t &out_data, bool isPriveleged) const;
  void writeByte(uint32_t address, uint8_t in_data);
  void readUnrestricted(uint32_t address, uint32_t& out_data);//allows reads from anywhere, used only for LWL and LWR which handle memory exceptions externally since changing the interface may require changes to past functions
  void readByte(uint32_t address, uint8_t& out_data);
};
#endif
