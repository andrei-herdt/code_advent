#include "day_three_utils.h"

#include <regex>

std::vector<size_t> ExtractClaim(const std::string& claim) {
    std::vector<size_t> claim_vec;
    std::regex id_regex("([0-9])");
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
    for (int i = 0; i < claim[3]; ++i) {
        for (int j = 0; j < claim[4]; ++j) {
            ++fabric[std::make_pair(claim[1] + i, claim[2] + j)];
        }
    }
}
