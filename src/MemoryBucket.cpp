#include "../include/MemoryBucket.h"

int MemoryBucket::get_bucket_value() {
  return this->value;
}

void MemoryBucket::set_bucket_value(int new_value) {
  this->value = new_value;
}