#include <map>
#include <string>
#include <vector>

using IdTotalMinutesMap = std::map<size_t, size_t>;
using IdMinutesMap = std::map<std::pair<size_t, size_t>, size_t>;

std::string ExtractFirstOccurence(const std::string& word,
                                  const std::string& pattern);

std::pair<IdTotalMinutesMap, IdMinutesMap> GenerateMap(
    const std::vector<std::string> sleep_times);
