#include "find_duplicate.h"

using namespace std;

string FindDuplicate(const vector<string>& words) {
    for (size_t col{0}; col < words.front().size(); ++col) {
        map<string, size_t> word_map;
        for (auto word : words) {
            word.erase(col, 1);
            if (++word_map[word] == 2) {
                return word;
            }
        }
    }
}
