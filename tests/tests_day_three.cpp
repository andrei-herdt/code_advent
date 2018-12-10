#include <gmock/gmock.h>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

TEST(day_three, part_one) {
    const vector<string> claims("#1 @ 1,3: 4x4", "#2 @ 3,1: 4x4",
                                "#3 @ 5,5: 2x2");

    map<pair<int, int>, size_t> fabric;

    for (int i = 1; i < 1 + 4; ++i) {
        for (int j = 1; j < 1 + 4; ++j) {
            ++fabric[make_pair(1 + i, 3 + j)];
        }
    }

    for (int i = 1; i < 1 + 4; ++i) {
        for (int j = 1; j < 1 + 4; ++j) {
            ++fabric[make_pair(3 + i, 1 + j)];
        }
    }

    int num_overlaps = count(map.begin(), map.end(),
                             [](int num_uses) { return num_uses > 1; });
    ASSERT_EQ(num_overlaps, 4);
}
