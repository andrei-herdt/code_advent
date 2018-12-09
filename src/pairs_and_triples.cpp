#include "pairs_and_triples.h"

void FindPairsAndTriples(const std::string& word, int& two_letters,
                         int& three_letters) {
    int number_same_letter{0};
    two_letters = 0;
    three_letters = 0;
    std::string word_copy(word);
    std::sort(std::begin(word_copy), std::end(word_copy));
    auto same_ptr =
        std::adjacent_find(std::begin(word_copy), std::end(word_copy));
    while (same_ptr != std::end(word_copy)) {
        number_same_letter =
            std::count(same_ptr, std::end(word_copy), *same_ptr);
        if (number_same_letter == 2) {
            two_letters = 1;
            same_ptr = std::next(same_ptr, 1);
        } else if (number_same_letter == 3) {
            three_letters = 1;
            same_ptr = std::next(same_ptr, 2);
        };
        same_ptr = std::adjacent_find(same_ptr, std::end(word_copy));
    }
};
