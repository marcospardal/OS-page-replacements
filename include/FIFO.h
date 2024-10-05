#ifndef FIFO_H
#define FIFO_H

#include "PageReplacement.h"

class FIFO : public PageReplacement {
  public:
    FIFO(int numero_quadros) : PageReplacement(numero_quadros, "FIFO ") {}

    void replace_page(int page) override;
};

#endif