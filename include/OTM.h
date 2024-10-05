#ifndef OTM_H
#define OTM_H

#include <vector>
#include <fstream>
#include <string>

#include "PageReplacement.h"

using namespace std;

class OTM : public PageReplacement {
  private:
    vector<int> next_pages_references;
    ifstream input;

  public:
    OTM(string input_path);

    void fill_next_references();

    void execute();

    void replace_page(int page) override;

    int find_remove_bucket_index();
};

#endif