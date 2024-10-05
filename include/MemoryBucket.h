#ifndef MEMORY_BUCKET_H
#define MEMORY_BUCKET_H


class MemoryBucket {
  private:
    int value;

    public:
      MemoryBucket(int value): value(value) {}

      int get_bucket_value();

      void set_bucket_value(int new_value);
};

#endif