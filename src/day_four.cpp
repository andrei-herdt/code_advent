#include <assert.h>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "day_four_utils.h"

using namespace std;

int main() {
    ifstream input_file;
    input_file.open("../data/day_four.txt");

    vector<string> sleep_times;
    string word;
    while (getline(input_file, word)) {
        sleep_times.push_back(word);
    }
    sort(begin(sleep_times), end(sleep_times));

    // Part one
    auto [total_sleep_times, total_sleep_minutes] = GenerateMap(sleep_times);

    auto longest_slept_id = max_element(
        begin(total_sleep_times), end(total_sleep_times),
        [](auto left, auto right) { return left.second < right.second; });

    vector<size_t> longest_slept_minutes(60, 0);
    for (size_t minute = 0; minute < 60; ++minute) {
        longest_slept_minutes[minute] =
            total_sleep_minutes[make_pair(longest_slept_id->first, minute)];
    }
    auto result =
        max_element(begin(longest_slept_minutes), end(longest_slept_minutes));
    size_t longest_slept_minute =
        distance(begin(longest_slept_minutes), result);

    cout << "id * minute = " << longest_slept_id->first * longest_slept_minute
         << endl;

    // Part two
    auto max_minutes = max_element(
        begin(total_sleep_minutes), end(total_sleep_minutes),
        [](auto left, auto right) { return left.second < right.second; });
    cout << "id * minute = "
         << max_minutes->first.first * max_minutes->first.second << endl;

    return 0;
}
