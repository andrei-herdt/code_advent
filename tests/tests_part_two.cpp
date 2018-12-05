#include <gmock/gmock.h>
#include <algorithm>
#include <numeric>

#include "part_two.h"

TEST(part_two, same_letter) {
    std::string word{"abcdef"};
    std::sort(std::begin(word), std::end(word));

    int two_letters{0};
    int three_letters{0};
    ASSERT_FALSE(two_letters == 1);
    ASSERT_FALSE(three_letters == 1);

    std::vector<std::string> words;
    word = "bababc";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_TRUE(two_letters == 1);
    ASSERT_TRUE(three_letters == 1);

    word = "abbcde";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_TRUE(two_letters == 1);
    ASSERT_FALSE(three_letters == 1);

    word = "abcccd";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_FALSE(two_letters == 1);
    ASSERT_TRUE(three_letters == 1);

    word = "aabcdd";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_TRUE(two_letters == 1);
    ASSERT_FALSE(three_letters == 1);

    word = "abcdee";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_TRUE(two_letters == 1);
    ASSERT_FALSE(three_letters == 1);

    word = "ababab";
    words.push_back(word);
    FindPairsAndTriples(word, two_letters, three_letters);
    ASSERT_FALSE(two_letters == 1);
    ASSERT_TRUE(three_letters == 1);

    int number_two_letter_words = 0;
    int number_three_letter_words = 0;
    for (std::string word : words) {
        FindPairsAndTriples(word, two_letters, three_letters);
        number_two_letter_words += two_letters;
        number_three_letter_words += three_letters;
    }
    ASSERT_FALSE(number_two_letter_words == 3);
    ASSERT_TRUE(number_three_letter_words == 3);
}
