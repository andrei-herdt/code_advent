#include <assert.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "day_three_utils.h"

int main() {
    std::ifstream input_file;
    input_file.open("../data/day_three.txt");

    std::vector<std::string> claims;
    std::string word;
    while (std::getline(input_file, word)) {
        claims.push_back(word);
    }

    std::map<std::pair<int, int>, size_t> fabric;
    std::multimap<std::pair<int, int>, size_t> mfabric;
    std::unordered_set<size_t> ids;
    for (auto claim : claims) {
        auto claim_int = ExtractClaim(claim);
        ids.insert(claim_int[0]);
        MakeClaim(ExtractClaim(claim), fabric);
        MakeMultiClaim(claim_int, mfabric);
    }

    // Part one
    auto num_overlaps = count_if(fabric.begin(), fabric.end(),
                                 [](auto& claim) { return claim.second > 1; });
    std::cout << "The number of overlaps is: " << num_overlaps << std::endl;

    // Part two
    for (auto it = std::begin(mfabric); it != std::end(mfabric); ++it) {
        if (mfabric.count(it->first) > 1) {
            ids.erase(it->second);
        }
    }

    assert(ids.size() == 1);
    std::cout << "The non-overlapping id is: " << *ids.begin() << std::endl;
    return 0;
}
