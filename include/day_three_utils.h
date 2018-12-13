#include <map>
#include <string>
#include <vector>

std::vector<size_t> ExtractClaim(const std::string& claim);

void MakeClaim(const std::vector<size_t>& claim,
               std::map<std::pair<int, int>, size_t>& fabric);
