#include "day_three_utils.h"

#include <iostream>
#include <regex>

std::vector<size_t> ExtractClaim(const std::string& claim) {
    std::vector<size_t> claim_vec;
    std::regex id_regex("([0-9]+)");
    auto words_begin =
        std::sregex_iterator(claim.begin(), claim.end(), id_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        claim_vec.push_back(stoi(match.str()));
    }
    return claim_vec;
}

void MakeClaim(const std::vector<size_t>& claim,
               std::map<std::pair<int, int>, size_t>& fabric) {
    size_t x{claim[1]};
    size_t y{claim[2]};
    size_t width{claim[3]};
    size_t height{claim[4]};
    for (size_t w = 0; w < width; ++w) {
        for (size_t h = 0; h < height; ++h) {
            ++fabric[std::make_pair(x + w, y + h)];
        }
    }
}
