#include "../include/LRU.h"

void LRU::replace_page(int page) {
  int last_used = this->find_last_used_bucket();

  if (last_used == -1) return;

  this->memory.erase(this->memory.begin() + last_used);
  this->create_item(page);
}

int LRU::find_last_used_bucket() {
  if (memory.empty())
    return -1;

  int last_used_index = 0;
  time_t last_used_time = memory[0].get_bucket_last_used();

  for (int index = 0; index < memory.size(); index++) {
    time_t current_last_used = memory[index].get_bucket_last_used();
    
    if (current_last_used < last_used_time) {
      last_used_time = current_last_used;
      last_used_index = index;
    }
  }

  return last_used_index;
}