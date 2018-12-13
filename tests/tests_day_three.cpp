#include <gmock/gmock.h>
#include <map>
#include <vector>

#include "day_three_utils.h"

TEST(day_three, part_one) {
    const std::vector<std::string> claims{"#1 @ 1,3: 4x4", "#2 @ 3,1: 4x4",
                                          "#3 @ 5,5: 2x2", "#4 @ 6,6: 1x1"};

    std::map<std::pair<int, int>, size_t> fabric;

    auto claim = ExtractClaim(claims[0]);
    MakeClaim(claim, fabric);

    claim = ExtractClaim(claims[1]);
    MakeClaim(claim, fabric);

    claim = ExtractClaim(claims[2]);
    MakeClaim(claim, fabric);

    claim = ExtractClaim(claims[3]);
    MakeClaim(claim, fabric);

    auto num_overlaps = count_if(fabric.begin(), fabric.end(),
                                 [](auto& claim) { return claim.second > 1; });
    ASSERT_EQ(num_overlaps, 5);
}
