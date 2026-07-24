#ifndef potentialSpork_H
#include "bitwidth.h"
#define potentialSpork_H
struct Ram {
  uintmax_t size;
  uint8_t * data;
  uint8_t type;
};
struct Rom {
  uintmax_t size;
  const uint8_t * data;
  uint8_t type;
};
typedef union Memory {
  struct Ram ram;
  struct Rom rom;
} Memory;
typedef struct MemoryMap {
  uintmax_t size;
  uint32_t length;
  uintmax_t * start;
  Memory ** data;
} MemoryMap;
#define MemType_Rom 255 // Data points to the contents. Immutable.
#define MemType_GeneralRam 0 // Data points to the contents
#define MemType_MMIORam 1 // Data points to a MMIO struct
#define MemType_VideoRam 2 // Data points to a video card struct
// TODO define Memory, Ram, Rom, and MemoryMap functions.
Memory* newRam(uintmax_t, uint8_t);
Memory* newRom(uintmax_t, const uint8_t *);
MemoryMap* newMemMap(uintmax_t, uint32_t);
void mmMap(MemoryMap*, Memory*, uintmax_t);
void mmUnmap(MemoryMap*, uintmax_t); // Unmaps the first listed item in the map.

uint8_t readMemory(Memory *, uintmax_t);
void writeMemory(Memory *, uintmax_t, uint8_t);
uint8_t mmRead8(MemoryMap*, uintmax_t);
void  mmWrite8(MemoryMap*, uintmax_t, uint8_t);
uint16_t mmRead16L(MemoryMap*, uintmax_t);
void  mmWrite16L(MemoryMap*, uintmax_t, uint16_t);
uint32_t mmRead32L(MemoryMap*, uintmax_t);
void  mmWrite32L(MemoryMap*, uintmax_t, uint32_t);
uint64_t mmRead64L(MemoryMap*, uintmax_t);
void  mmWrite64L(MemoryMap*, uintmax_t, uint64_t);
uint16_t mmRead16B(MemoryMap*, uintmax_t);
void  mmWrite16B(MemoryMap*, uintmax_t, uint16_t);
uint32_t mmRead32B(MemoryMap*, uintmax_t);
void  mmWrite32B(MemoryMap*, uintmax_t, uint32_t);
uint64_t mmRead64B(MemoryMap*, uintmax_t);
void  mmWrite64B(MemoryMap*, uintmax_t, uint64_t);
#endif
