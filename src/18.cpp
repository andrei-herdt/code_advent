#include <assert.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ifstream input_file;
    input_file.open("../data/18.txt");

    vector<string> state;
    string word;
    while (getline(input_file, word)) {
        state.push_back(word);
    }

    std::map<pair<size_t, size_t>, char> field;
    for (size_t row = 0; row < state.size(); ++row) {
        for (int col = 0; col < state[0].size(); ++col) {
            field[make_pair(row, col)] = state[row][col];
        }
    }
    auto new_field{field};
    auto tmp_field{field};

    auto get_region = [&new_field](size_t posx, size_t posy) {
        vector<char> region;
        auto range = {-1, 0, 1};
        for (size_t dx : range) {
            for (size_t dy : range) {
                if (dx | dy) {
                    pair<size_t, size_t> pos(posx + dx, posy + dy);
                    if (new_field.find(pos) != end(new_field)) {
                        region.push_back(new_field[pos]);
                    }
                }
            }
        }
        return region;
    };

    for (int i = 0; i < 10; ++i) {
        for (size_t x = 0; x < state.size(); ++x) {
            for (size_t y = 0; y < state[0].size(); ++y) {
                auto region = get_region(x, y);
                size_t num_trees = count(begin(region), end(region), '|');
                size_t num_lumb = count(begin(region), end(region), '#');
                char value = new_field[make_pair(x, y)];
                char new_value{value};
                // An open acre will become filled with trees if three or more
                // adjacent acres contained trees. Otherwise, nothing happens.
                if (value == '.' && num_trees > 2) {
                    new_value = '|';
                }
                //     An acre filled with trees will become a lumberyard if
                //     three or more adjacent acres were lumberyards. Otherwise,
                //     nothing happens.
                if (value == '|' && num_lumb > 2) {
                    new_value = '#';
                }
                //     An acre containing a lumberyard will remain a lumberyard
                //     if it was adjacent to at least one other lumberyard and
                //     at least one acre containing trees. Otherwise, it becomes
                //     open.
                if (value == '#') {
                    if (num_lumb > 0 && num_trees > 0) {
                        new_value = '#';
                    } else {
                        new_value = '.';
                    }
                }
                tmp_field[make_pair(x, y)] = new_value;
            }
        }
        new_field = tmp_field;
    }

    vector<char> acres;
    for (auto it = begin(new_field); it != end(new_field); ++it) {
        acres.push_back(it->second);
    }
    size_t num_trees = count(begin(acres), end(acres), '|');
    size_t num_lumb = count(begin(acres), end(acres), '#');
    std::cout << num_trees * num_lumb << std::endl;
}
