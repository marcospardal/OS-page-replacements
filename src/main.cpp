#include <iostream>
#include <fstream>
#include <string>

#include "../include/FIFO.h"

using namespace std;

int main() {
  cout << "Iniciando simulação de algoritmos de substgituição" << endl;
  ifstream inputFile("../input.txt");

  if (!inputFile.is_open()) {
    cerr << "Erro ao abrir arquivo" << endl;
    return 1;
  }

  string line;
  // lê número de buckets
  getline(inputFile, line);
  int n_memory_buckets = stoi(line);
  FIFO fifo_queue = FIFO(n_memory_buckets);


  while (getline(inputFile, line)) {
    int current_page = stoi(line);
    fifo_queue.add_page(current_page);
  }

  fifo_queue.display_faltas();

  return 0;
}