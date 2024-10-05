#include <iostream>
#include <fstream>
#include <string>

#include "../include/FIFO.h"
#include "../include/LRU.h"

using namespace std;

int main() {
  cout << "Iniciando simulacao de algoritmos de substituicao" << endl;
  ifstream inputFile("../input.txt");

  if (!inputFile.is_open()) {
    cerr << "Erro ao abrir arquivo" << endl;
    return 1;
  }

  string line;
  getline(inputFile, line);
  int n_memory_buckets = stoi(line);
  FIFO fifo_queue = FIFO(n_memory_buckets);
  LRU lru_queue = LRU(n_memory_buckets);


  while (getline(inputFile, line)) {
    int current_page = stoi(line);
    fifo_queue.reference_page(current_page);
    lru_queue.reference_page(current_page);
  }

  fifo_queue.display_faltas();
  lru_queue.display_faltas();

  return 0;
}