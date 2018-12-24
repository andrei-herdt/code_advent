#include <gmock/gmock.h>
#include <regex>

std::string ExtractFirstOccurence(const std::string& word,
                                  const std::string& pattern) {
    std::regex id_regex(pattern);
    auto words_begin = std::sregex_iterator(word.begin(), word.end(), id_regex);
    auto words_end = std::sregex_iterator();
    return words_begin->str();
}

std::vector<std::string> ExtractAllOccurences(const std::string& word,
                                              const std::string& pattern) {
    std::vector<std::string> matches;
    std::regex id_regex(pattern);
    auto words_begin = std::sregex_iterator(word.begin(), word.end(), id_regex);
    auto words_end = std::sregex_iterator();
    for (auto it = words_begin; it != words_end; ++it) {
        matches.push_back(it->str());
    }
    return matches;
}

TEST(day_four, part_one) {
    const std::vector<std::string> sleep_times{
        "[1518 - 11 - 01 00:00] Guard #10 begins shift",
        "[1518 - 11 - 01 00:05] falls asleep [1518 - 11 - 01 00:25] wakes "
        "up",
        "[1518 - 11 - 01 00:30] falls asleep [1518 - 11 - 01 00:55] wakes "
        "up",
        "[1518 - 11 - 01 23:58] Guard #99 begins shift",
        "[1518 - 11 - 02 00:40] falls asleep [1518 - 11 - 02 00:50] wakes "
        "up",
        "[1518 - 11 - 03 00:05] Guard #10 begins shift",
        "[1518 - 11 - 03 00:24] falls asleep [1518 - 11 - 03 00:29] wakes "
        "up",
        "[1518 - 11 - 04 00:02] Guard #99 begins shift",
        "[1518 - 11 - 04 00:36] falls asleep [1518 - 11 - 04 00:46] wakes "
        "up",
        "[1518 - 11 - 05 00:03] Guard #99 begins shift",
        "[1518 - 11 - 05 00:45] falls asleep [1518 - 11 - 05 00:55] wakes "
        "up"};

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
    std::multimap<std::pair<size_t, size_t>, size_t> sleep_minutes;
    size_t current_id{0};
    for (size_t i = 0; i < sleep_times.size(); ++i) {
        auto id = ExtractFirstOccurence(sleep_times[i], "#([0-9]+)");
        auto period = ExtractAllOccurences(sleep_times[i], "\\d\\d:\\d\\d");
        if (!id.empty()) {
            current_id = stoi(id.erase(0, 1));
        };
        if (id.empty()) {
            size_t sleep_begin = stoi(period[0].substr(3));
            size_t sleep_end = stoi(period[1].substr(3));

            for (size_t minute = sleep_begin; minute < sleep_end; minute++) {
                std::pair<size_t, size_t> key(current_id, minute);
                sleep_minutes.insert(std::make_pair(key, 1));
            }
        }
    }

    /*Integrate map*/
    std::map<size_t, size_t> total_sleep_times;
    std::map<std::pair<size_t, size_t>, size_t> total_sleep_minutes;
    for (auto it = sleep_minutes.begin(); it != sleep_minutes.end(); ++it) {
        total_sleep_times[it->first.first] += it->second;
        total_sleep_minutes[it->first] += it->second;
    }
    auto longest_slept_id = std::max_element(
        std::begin(total_sleep_times), std::end(total_sleep_times),
        [](auto left, auto right) { return left.second < right.second; });
    ASSERT_EQ(longest_slept_id->first, 10);

    std::vector<size_t> longest_slept_minutes(60, 0);
    for (size_t minute = 0; minute < 60; ++minute) {
        longest_slept_minutes[minute] = total_sleep_minutes[std::make_pair(
            longest_slept_id->first, minute)];
    }
    auto result = std::max_element(std::begin(longest_slept_minutes),
                                   std::end(longest_slept_minutes));
    size_t longest_slept_minute =
        std::distance(std::begin(longest_slept_minutes), result);
    ASSERT_EQ(longest_slept_minute, 24);

    int id = 10;
    int minute = 24;
    ASSERT_EQ(id * minute, 240);
}
