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
  int remove_index = this->find_remove_bucket_index();

  if (remove_index != -1) {
    this->memory.erase(this->memory.begin() + remove_index);
    this->create_item(page);
  }
}

int OTM::find_remove_bucket_index() {
  std::vector<int> next_references_indexes(this->numero_quadros, -1);

  for (int index = 0; index < this->memory.size(); index++) {
    for (int next_reference_index = 0; next_reference_index < this->next_pages_references.size(); next_reference_index++) {
      if (this->next_pages_references[next_reference_index] == this->memory[index].get_bucket_value()) {
        next_references_indexes[index] = next_reference_index;
        break;
      }
    }
  }

  int remove_index = -1;

  for (int current_index = 0; current_index < this->memory.size(); current_index++) {
    if (next_references_indexes[current_index] == -1) {
      remove_index = current_index;
      break;
    } else if (remove_index == -1 || 
      next_references_indexes[current_index] > next_references_indexes[remove_index]) {
      remove_index = current_index;
    }
  }

  return remove_index;
}