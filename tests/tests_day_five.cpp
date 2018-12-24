#include <gmock/gmock.h>
#include <numeric>

using namespace std;

TEST(day_five, part_one) {
    string polymer{"dabAcCaCBAcCcaDA"};
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
    ASSERT_EQ(polymer.size(), 10);
}
