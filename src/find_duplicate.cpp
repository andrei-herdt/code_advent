#include "find_duplicate.h"

using namespace std;

string FindDuplicate(const vector<string>& words) {
    for (size_t i = 0; i < words[0].size(); ++i) {
        vector<string> shortened_words(words);
        for (auto& word : shortened_words) {
            word[i] = '*';
        }
        map<string, size_t> word_map;
        string duplicate_word;
        for (auto& word : shortened_words) {
            if (++word_map[word] == 2) {
                return word.erase(i, 1);
            }
        }
    }
}
