#include "day_four_utils.h"

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

std::multimap<std::pair<size_t, size_t>, size_t> GenerateSleepingMultiMap(
    const std::vector<std::string> sleep_times) {
    std::multimap<std::pair<size_t, size_t>, size_t> sleep_minutes;
    size_t current_id{0};
    for (size_t i = 0; i < sleep_times.size(); ++i) {
        auto id = ExtractFirstOccurence(sleep_times[i], "#([0-9]+)");
        auto period = ExtractAllOccurences(sleep_times[i], ":\\d\\d");
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
    return sleep_minutes;
}

std::pair<size_t, size_t> FindLongestSleepingIdMinute(
    const std::multimap<std::pair<size_t, size_t>, size_t>& sleep_minutes) {
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

    std::vector<size_t> longest_slept_minutes(60, 0);
    for (size_t minute = 0; minute < 60; ++minute) {
        longest_slept_minutes[minute] = total_sleep_minutes[std::make_pair(
            longest_slept_id->first, minute)];
    }
    auto result = std::max_element(std::begin(longest_slept_minutes),
                                   std::end(longest_slept_minutes));
    size_t longest_slept_minute =
        std::distance(std::begin(longest_slept_minutes), result);
    return std::make_pair(longest_slept_id->first, longest_slept_minute);
}
