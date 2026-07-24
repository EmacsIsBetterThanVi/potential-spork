#include "potentialSpork.h"
#include <stdlib.h>
Memory* newRam(uintmax_t size, uint8_t type){
  Memory* mem = malloc(sizeof(Memory));
  mem->ram.type = type;
  mem->ram.size = size;
  mem->ram.data = calloc(size, 1);
  return mem;
}
Memory* newRom(uintmax_t size, const uint8_t * data){
  Memory* mem = malloc(sizeof(Memory));
  mem->rom.type = MemType_Rom;
  mem->rom.size = size;
  mem->rom.data = data;
  return mem;
}
uint8_t readMem(Memory * mem, uintmax_t addr) {
  return mem->ram.data[addr];
}
void writeMem(Memory * mem, uintmax_t addr, uint8_t data){
  mem->ram.data[addr] = data;
}
uint8_t readMemory(Memory * mem, uintmax_t addr) {
  switch (mem->ram.type){
    case MemType_VideoRam:
      break;
    case MemType_MMIORam:
      break;
    default:
      return readMem(mem, addr);
      break; 
  }
}
void writeMemory(Memory * mem, uintmax_t addr, uint8_t data){
  switch (mem->ram.type){
    case MemType_Rom: // No error, but prevent writing.
      break;
    case MemType_VideoRam:
      break;
    case MemType_MMIORam:
      break;
    default:
      return writeMem(mem, addr, data);
      break;
  }
}
MemoryMap* newMemMap(uintmax_t size, uint32_t expected){
  MemoryMap* mm = malloc(sizeof(MemoryMap));
  mm->length=expected;
  mm->size=size;
  mm->start = calloc(expected, sizeof(uintmax_t));
  mm->data = calloc(expected, sizeof(Memory*));
  return mm;
}
void mmMap(MemoryMap* mm, Memory* mem, uintmax_t addr){
  for (uint32_t i=0; i<mm->size; i++){
  }
  Memory ** data = mm->data;
  uintmax_t * start = mm->start;
  mm->size*=2
  mm->data = calloc(mm->size, sizeof(Memory*))
}
void mmUnmap(MemoryMap* mm, uintmax_t addr);

uint8_t mmRead8(MemoryMap* mm, uintmax_t addr);
void  mmWrite8(MemoryMap* mm, uintmax_t addr, uint8_t value);
uint16_t mmRead16L(MemoryMap* mm, uintmax_t addr);
void  mmWrite16L(MemoryMap* mm, uintmax_t addr, uint16_t value);
uint32_t mmRead32L(MemoryMap* mm, uintmax_t addr);
void  mmWrite32L(MemoryMap* mm, uintmax_t addr, uint32_t value);
uint64_t mmRead64L(MemoryMap* mm, uintmax_t addr);
void  mmWrite64L(MemoryMap* mm, uintmax_t addr, uint64_t value);
uint16_t mmRead16B(MemoryMap* mm, uintmax_t addr);
void  mmWrite16B(MemoryMap* mm, uintmax_t addr, uint16_t value);
uint32_t mmRead32B(MemoryMap* mm, uintmax_t addr);
void  mmWrite32B(MemoryMap* mm, uintmax_t addr, uint32_t value);
uint64_t mmRead64B(MemoryMap* mm, uintmax_t addr);
void  mmWrite64B(MemoryMap* mm, uintmax_t addr, uint64_t value);
