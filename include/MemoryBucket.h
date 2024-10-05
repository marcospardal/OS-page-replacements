#ifndef MEMORY_BUCKET_H
#define MEMORY_BUCKET_H

#include <time.h>


class MemoryBucket {
  private:
    int value;
    time_t last_used;

    public:
      MemoryBucket(int value): value(value) {}

      int get_bucket_value();

      time_t get_bucket_last_used();

      void set_bucket_value(int new_value);

      void use_bucket();
};

#endif