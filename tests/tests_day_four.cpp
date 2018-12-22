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
        auto period = ExtractAllOccurences(sleep_times[i], "asleep");
        if (!id.empty()) {
            current_id = stoi(id.erase(0, 1));
        };
        if (!period.empty()) {
            for (auto match : period) {
                std::cout << match << std::endl;
            }
        }
    }

    int id = 10;
    int minute = 24;
    ASSERT_EQ(id * minute, 240);
}
