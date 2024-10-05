#ifndef LRU_H
#define LRU_H

#include "PageReplacement.h"

class LRU : public PageReplacement {
  public:
    LRU(int numero_quadros) : PageReplacement(numero_quadros, "LRU") {}

    void replace_page(int page) override;

    int find_last_used_bucket();
};

#endif