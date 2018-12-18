#include <gmock/gmock.h>
#include <map>
#include <unordered_set>
#include <vector>

#include "day_three_utils.h"

TEST(day_three, part_one) {
    const std::vector<std::string> claims{"#1 @ 1,3: 4x4", "#2 @ 3,1: 4x4",
                                          "#3 @ 5,5: 2x2", "#4 @ 6,6: 1x1"};

    std::map<std::pair<int, int>, size_t> fabric;

    MakeClaim(ExtractClaim(claims[0]), fabric);
    MakeClaim(ExtractClaim(claims[1]), fabric);
    MakeClaim(ExtractClaim(claims[2]), fabric);
    MakeClaim(ExtractClaim(claims[3]), fabric);

    auto num_overlaps = count_if(fabric.begin(), fabric.end(),
                                 [](auto& claim) { return claim.second > 1; });
    ASSERT_EQ(num_overlaps, 5);
}

TEST(day_three, part_two) {
    const std::vector<std::string> claims{"#1 @ 1,3: 4x4", "#2 @ 3,1: 4x4",
                                          "#3 @ 5,5: 2x2"};

    std::multimap<std::pair<int, int>, size_t> fabric;
    std::unordered_set<size_t> ids;
    std::vector<size_t> claim_int;
    for (auto claim : claims) {
        claim_int = ExtractClaim(claim);
        ids.insert(claim_int[0]);
        MakeMultiClaim(claim_int, fabric);
    }

    for (auto it = std::begin(fabric); it != std::end(fabric); ++it) {
        if (fabric.count(it->first) > 1) {
            ids.erase(it->second);
        }
    }

    ASSERT_EQ(ids.size(), 1);
    ASSERT_EQ(*ids.begin(), 3);
}
