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
    vector<MemoryBucket> memory;

  public:
    PageReplacement(int numero_quadros, string tipo);

    void initialize_memory();

    void update_numero_quadros(int numero);

    virtual void replace_page(int page) = 0;

    int search_page(int page);

    void reference_page(int page);

    void insert_page(int page);

    void use_page(int page);

    bool can_add_item();

    void create_item(int page);

    void display_faltas();
};

#endif