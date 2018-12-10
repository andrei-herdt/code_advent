#include <gmock/gmock.h>

#include <numeric>

TEST(part_one, foo) {
    std::vector<int> freq_changes{1, -1};
    std::vector<int> frequencies(2, 0);

    // Coompute frequencies
    auto append = [](std::vector<int> v, int c) { return v.push_back(c); };
    std::partial_sum(freq_changes.begin(), freq_changes.end(),
                     frequencies.begin());

    ASSERT_THAT(frequencies, testing::ElementsAre(1, 0));
}
