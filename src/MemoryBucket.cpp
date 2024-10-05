#include "../include/MemoryBucket.h"

int MemoryBucket::get_bucket_value() {
  return this->value;
}

void MemoryBucket::set_bucket_value(int new_value) {
  this->value = new_value;
  this->use_bucket();
}

void MemoryBucket::use_bucket() {
  this->last_used = time(NULL);
}

time_t MemoryBucket::get_bucket_last_used() {
  return this->last_used;
}