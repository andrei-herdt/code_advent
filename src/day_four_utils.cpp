#include "day_four_utils.h"
#include <iostream>

#include <regex>

using namespace std;

string ExtractFirstOccurence(const string& word, const string& pattern) {
    regex id_regex(pattern);
    auto words_begin = sregex_iterator(word.begin(), word.end(), id_regex);
    auto words_end = sregex_iterator();
    return words_begin->str();
}

pair<IdTotalMinutesMap, IdMinutesMap> GenerateMap(
    const vector<string> sleep_times) {
    size_t current_id{0};
    size_t sleep_begin{0};
    size_t sleep_end{0};
    map<size_t, size_t> total_sleep_times;
    map<pair<size_t, size_t>, size_t> total_sleep_minutes;
    for (size_t i = 0; i < sleep_times.size(); ++i) {
        if (sleep_times[i].find("Guard") != string::npos) {
            auto id = ExtractFirstOccurence(sleep_times[i], "#([0-9]+)");
            current_id = stoi(id.erase(0, 1));
        } else if (sleep_times[i].find("asleep") != string::npos) {
            auto period = ExtractFirstOccurence(sleep_times[i], ":\\d\\d");
            sleep_begin = stoi(period.erase(0, 1));
        } else if (sleep_times[i].find("wakes") != string::npos) {
            auto period = ExtractFirstOccurence(sleep_times[i], ":\\d\\d");
            sleep_end = stoi(period.erase(0, 1));
            for (size_t minute = sleep_begin; minute < sleep_end; minute++) {
                pair<size_t, size_t> key(current_id, minute);
                ++total_sleep_times[current_id];
                ++total_sleep_minutes[key];
            }
        }
    }
    return make_pair(total_sleep_times, total_sleep_minutes);
}
