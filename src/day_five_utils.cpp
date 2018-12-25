#include "day_five_utils.h"

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void React(string& polymer) {
    vector<char> diffs(polymer.size(), 0);
    adjacent_difference(polymer.begin(), polymer.end(), diffs.begin());
    while (1) {
        fill(begin(diffs), end(diffs), 0);
        adjacent_difference(polymer.begin(), polymer.end(), diffs.begin());
        auto Xx = find(begin(diffs), end(diffs), 32);
        if (Xx != end(diffs)) {
            auto pos = distance(begin(diffs), Xx);
            polymer.erase(pos - 1, 2);
        }

        fill(begin(diffs), end(diffs), 0);
        adjacent_difference(polymer.begin(), polymer.end(), diffs.begin());
        auto xX = find(begin(diffs), end(diffs), -32);
        if (xX != end(diffs)) {
            auto pos = distance(begin(diffs), xX);
            polymer.erase(pos - 1, 2);
        }
        if (xX == end(diffs) && Xx == end(diffs)) {
            break;
        }
    }
}
