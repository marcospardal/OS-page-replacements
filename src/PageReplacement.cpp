#include "../include/PageReplacement.h"

PageReplacement::PageReplacement(int numero_quadros, std::string tipo) {
  this->numero_quadros = numero_quadros;
  this->tipo = tipo;

  this->initialize_memory();
}

void PageReplacement::initialize_memory() {
  this->memory.reserve(this->numero_quadros);
}

bool PageReplacement::search_page(int page) {
  for (auto& bucket : memory) {
    if (bucket.get_bucket_value() == page) {
      return true;
    }
  }
  return false;
}

void PageReplacement::add_page(int page) {
  bool havePage = this->search_page(page);

  if (!havePage) {
    this->faltas_paginas++;

    if (this->can_add_item()) this->create_item(page);
    else this->replace_page(page);
  }
}

bool PageReplacement::can_add_item() {
  return this->memory.size() < this->numero_quadros;
}

void PageReplacement::create_item(int page) {
  MemoryBucket new_item = MemoryBucket(page);

  this->memory.push_back(new_item);
}

void PageReplacement::display_faltas() {
  std::cout << this->tipo << " " << this->faltas_paginas << std::endl;
}