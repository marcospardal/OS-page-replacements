#include "../include/FIFO.h"

void FIFO::replace_page(int page) {
  if (memory.empty()) return;

  memory.erase(memory.begin());

  this->create_item(page);
}