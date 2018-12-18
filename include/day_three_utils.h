#include <map>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<size_t> ExtractClaim(const std::string& claim);

void MakeClaim(const std::vector<size_t>& claim,
               std::map<std::pair<int, int>, size_t>& fabric);

void MakeMultiClaim(const std::vector<size_t>& claim,
                    std::multimap<std::pair<int, int>, size_t>& fabric);
