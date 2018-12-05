#include <gmock/gmock.h>
#include <numeric>

TEST(part_two, foo) {
    std::string word{"abcdef"};
    std::sort(std::begin(word), std::end(word));

    bool two_letters{false};
    bool three_letters{false};
    ASSERT_FALSE(two_letters);
    ASSERT_FALSE(three_letters);

    word = "bababc";
    std::sort(std::begin(word), std::end(word));
    auto same_ptr = std::adjacent_find(std::begin(word), std::end(word));
    while (same_ptr != std::end(word)) {
        count_if(same_ptr, std::end(word), *same_ptr);
        if (== 2) {
            two_letters = true;
        }
        else if(cou;
    }
    bool two_letters{false};
    bool three_letters{false};
    ASSERT_TRUE(two_letters);
    ASSERT_TRUE(three_letters);
}
