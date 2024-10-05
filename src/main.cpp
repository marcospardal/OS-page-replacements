#include <iostream>
#include <fstream>
#include <string>

#include "../include/FIFO.h"
#include "../include/LRU.h"
#include "../include/OTM.h"

using namespace std;

int main() {
  cout << "Iniciando simulacao de algoritmos de substituicao" << endl;
  string file_path = "../input.txt";
  ifstream input_file(file_path);

  if (!input_file.is_open()) {
    cerr << "Erro ao abrir arquivo" << endl;
    return 1;
  }

  string line;
  getline(input_file, line);
  int n_memory_buckets = stoi(line);

  FIFO fifo_queue = FIFO(n_memory_buckets);
  LRU lru_queue = LRU(n_memory_buckets);


  while (getline(input_file, line)) {
    int current_page = stoi(line);
    fifo_queue.reference_page(current_page);
    lru_queue.reference_page(current_page);
  }

  OTM otm_queue = OTM(file_path);
  otm_queue.execute();

  fifo_queue.display_faltas();
  otm_queue.display_faltas();
  lru_queue.display_faltas();

  return 0;
}