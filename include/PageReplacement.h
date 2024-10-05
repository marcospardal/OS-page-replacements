#ifndef PAGE_REPLACEMENT_H
#define PAGE_REPLACEMENT_H

#include "MemoryBucket.h"
#include <iostream>
#include <vector>

using namespace std;

class PageReplacement {
  protected:
    int numero_quadros = 0;
    int faltas_paginas = 0;
    string tipo;
    std::vector<MemoryBucket> memory;

  public:
    PageReplacement(int numero_quadros, string tipo);

    void initialize_memory();

    virtual void replace_page(int page) = 0;

    bool search_page(int page);

    void add_page(int page);

    bool can_add_item();

    void create_item(int page);

    void display_faltas();
};

#endif