#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "find_duplicate.h"
#include "pairs_and_triples.h"

int main() {
    std::ifstream input_file;
    input_file.open("../data/second_day.txt");

    std::vector<std::string> words;
    std::string word;
    while (input_file >> word) {
        words.push_back(word);
    }

    std::vector<std::string> pairs_and_triples(words);
    int num_doubles{0};
    int num_triples{0};
    for (auto& pairs_and_triples : pairs_and_triples) {
        int double_found{0};
        int triple_found{0};
        FindPairsAndTriples(pairs_and_triples, double_found, triple_found);
        num_doubles += double_found;
        num_triples += triple_found;
    }
    std::cout << "The resulting hash is: " << num_doubles * num_triples
              << std::endl;

    std::cout << "The common letters between the two correct box IDs are: "
              << FindDuplicate(words) << std::endl;

    return 0;
}
