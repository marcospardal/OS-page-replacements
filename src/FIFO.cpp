#include "../include/FIFO.h"

void FIFO::replace_page(int page) {
  if (memory.empty()) return;

  memory.erase(memory.begin());

  MemoryBucket new_element = MemoryBucket(page);
  memory.push_back(new_element);
}