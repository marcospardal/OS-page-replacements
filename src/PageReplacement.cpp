#include "../include/PageReplacement.h"

PageReplacement::PageReplacement(int numero_quadros, std::string tipo) {
  this->numero_quadros = numero_quadros;
  this->tipo = tipo;

  this->initialize_memory();
}

void PageReplacement::initialize_memory() {
  this->memory.clear();
  this->memory.reserve(this->numero_quadros);
}

int PageReplacement::search_page(int page) {
  for (int index = 0; index < memory.size(); index++) {
    if (memory[index].get_bucket_value() == page) {
      return index;
    }
  }

  return -1;
}

void PageReplacement::reference_page(int page) {
  int page_index = this->search_page(page);
  bool have_page = page_index != -1;

  if (!have_page) this->insert_page(page);
  else this->use_page(page_index);
}

void PageReplacement::insert_page(int page) {
  this->faltas_paginas++;

  if (this->can_add_item()) this->create_item(page);
  else this->replace_page(page);
}

void PageReplacement::use_page(int bucket_index) {
  this->memory[bucket_index].use_bucket();
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

void PageReplacement::update_numero_quadros(int numero_quadros) {
  this->numero_quadros = numero_quadros;
  this->initialize_memory();
}