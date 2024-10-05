#include "../include/OTM.h"

using namespace std;

OTM::OTM(string input_path): PageReplacement(0, "OTM") {
  this->input.open(input_path);

  string line;
  getline(input, line);

  int n_buckets = stoi(line);

  this->update_numero_quadros(n_buckets);
  this->fill_next_references();
}

void OTM::fill_next_references() {
  string line;
  while(getline(this->input, line)) {
    int future_reference = stoi(line);

    this->next_pages_references.push_back(future_reference);
  }

  this->input.close();
}

void OTM::execute() {
  while(this->next_pages_references.size()) {
    // int next_page = this->next_pages_references.begin();

    this->reference_page(this->next_pages_references[0]);
    this->next_pages_references.erase(this->next_pages_references.begin());
  }
}

void OTM::replace_page(int page) {
    std::vector<int> next_references_indexes(this->numero_quadros, -1);

    // Preenche o vetor next_references_indexes
    for (int index = 0; index < this->memory.size(); index++) {
      for (int next_reference_index = 0; next_reference_index < this->next_pages_references.size(); next_reference_index++) {
        if (this->next_pages_references[next_reference_index] == this->memory[index].get_bucket_value()) {
          next_references_indexes[index] = next_reference_index;
          break; // Não precisa continuar procurando se já encontrou
        }
      }
    }

    int remove_index = -1; // Inicializa como -1 para indicar "nenhum"

    // Determina qual índice remover
    for (int current_index = 0; current_index < this->memory.size(); current_index++) {
      if (next_references_indexes[current_index] == -1) {
        // Se não há referência futura, considere como candidato para remoção
        remove_index = current_index;
        break; // Se encontrar um sem referência, use-o
      } else if (remove_index == -1 || 
        next_references_indexes[current_index] > next_references_indexes[remove_index]) {
        // Caso encontre um índice com uma referência futura mais distante
        remove_index = current_index;
      }
    }

    // Verifica se um índice válido foi encontrado para remoção
    if (remove_index != -1) {
      this->memory.erase(this->memory.begin() + remove_index);
    }

    // Adiciona a nova página
    this->create_item(page);
}