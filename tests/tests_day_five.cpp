#include <gmock/gmock.h>
#include <algorithm>
#include <numeric>

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

TEST(day_five, part_one) {
    string polymer{"dabAcCaCBAcCcaDA"};
    React(polymer);
    ASSERT_EQ(polymer.size(), 10);
}

TEST(day_five, part_two) {
    string polymer{"dabAcCaCBAcCcaDA"};

    polymer.erase(remove(begin(polymer), end(polymer), 'a'), end(polymer));
    polymer.erase(remove(begin(polymer), end(polymer), 'A'), end(polymer));
    React(polymer);
    ASSERT_EQ(polymer.size(), 6);

    polymer = "dabAcCaCBAcCcaDA";
    polymer.erase(remove(begin(polymer), end(polymer), 'b'), end(polymer));
    polymer.erase(remove(begin(polymer), end(polymer), 'B'), end(polymer));
    React(polymer);
    ASSERT_EQ(polymer.size(), 8);
}
