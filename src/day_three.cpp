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
    for (auto claim : claims) {
        MakeClaim(ExtractClaim(claim), fabric);
    }

    auto num_overlaps = count_if(fabric.begin(), fabric.end(),
                                 [](auto& claim) { return claim.second > 1; });
    std::cout << "The number of overlaps is: " << num_overlaps << std::endl;

    return 0;
}
