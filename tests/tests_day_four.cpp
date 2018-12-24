#include <gmock/gmock.h>
#include <regex>

#include "day_four_utils.h"

using namespace std;

TEST(day_four, part_one) {
    const std::vector<std::string> sleep_times{
        "[1518-11-01 00:00] Guard #10 begins shift",
        "[1518-11-01 00:05] falls asleep",
        "[1518-11-01 00:25] wakes up",
        "[1518-11-01 00:30] falls asleep",
        "[1518-11-01 00:55] wakes up",
        "[1518-11-01 23:58] Guard #99 begins shift",
        "[1518-11-02 00:40] falls asleep",
        "[1518-11-02 00:50] wakes up",
        "[1518-11-03 00:05] Guard #10 begins shift",
        "[1518-11-03 00:24] falls asleep",
        "[1518-11-03 00:29] wakes up",
        "[1518-11-04 00:02] Guard #99 begins shift",
        "[1518-11-04 00:36] falls asleep",
        "[1518-11-04 00:46] wakes up",
        "[1518-11-05 00:03] Guard #99 begins shift",
        "[1518-11-05 00:45] falls asleep",
        "[1518-11-05 00:55] wakes up"};
    /*
    Find guard with most sleeping time
     Extract gaurd id, sleeping time period
     Convert into keys of [id, 0-59]
     Populate 2dimensional multimap with ones for every sleeping minute
     Sum of sleeping minutes for each instance of specific id over all time
     Take max -> id
     Sum of sleeping minutes for each minute over all instances of specific
     id Take max -> minute
    */
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

    ASSERT_EQ(longest_slept_id->first * longest_slept_minute, 240);

    // Part two
    auto max_minutes = max_element(
        begin(total_sleep_minutes), end(total_sleep_minutes),
        [](auto left, auto right) { return left.second < right.second; });

    ASSERT_EQ(max_minutes->first.first, 99);
    ASSERT_EQ(max_minutes->first.second, 45);
    ASSERT_EQ(max_minutes->second, 3);
}
