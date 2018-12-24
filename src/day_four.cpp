#include <assert.h>
#include <fstream>
#include <iostream>

#include "day_four_utils.h"

int main() {
    std::ifstream input_file;
    input_file.open("../data/day_four.txt");

    std::vector<std::string> sleep_times;
    std::string word;
    while (std::getline(input_file, word)) {
        sleep_times.push_back(word);
        std::cout << word << std::endl;
    }

    // Part one
    auto sleep_minutes = GenerateSleepingMultiMap(sleep_times);

    auto [longest_id, longest_minute] =
        FindLongestSleepingIdMinute(sleep_minutes);

    std::cout << "id * minute = " << longest_id * longest_minute << std::endl;

    return 0;
}
