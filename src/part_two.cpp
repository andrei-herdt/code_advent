#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "pairs_and_triples.h"

int main() {
    std::ifstream input_file;
    input_file.open("../data/second_day.txt");

    std::vector<std::string> words;
    std::string word;
    while (input_file >> word) {
        words.push_back(word);
    }

    int num_doubles{0};
    int num_triples{0};
    for (auto& word : words) {
        int double_found{0};
        int triple_found{0};
        FindPairsAndTriples(word, double_found, triple_found);
        num_doubles += double_found;
        num_triples += triple_found;
    }
    std::cout << "The resulting hash is: " << num_doubles * num_triples
              << std::endl;

    return 0;
}
