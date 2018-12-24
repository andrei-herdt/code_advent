#include <map>
#include <string>
#include <vector>

std::string ExtractFirstOccurence(const std::string& word,
                                  const std::string& pattern);

std::vector<std::string> ExtractAllOccurences(const std::string& word,
                                              const std::string& pattern);

std::multimap<std::pair<size_t, size_t>, size_t> GenerateSleepingMultiMap(
    const std::vector<std::string> sleep_times);

std::pair<size_t, size_t> FindLongestSleepingIdMinute(
    const std::multimap<std::pair<size_t, size_t>, size_t>& sleep_minutes);
