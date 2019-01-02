#include <assert.h>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<size_t> scores;

    scores.insert(end(scores), 3);
    scores.insert(end(scores), 7);

    // @todo implement circular buffer
    auto cur1 = begin(scores);
    auto cur2 = cur1++;
    size_t num_ones = 0;
    for (int i = 0; i < 10; ++i) {
        // gen new recipes
        size_t sumcur = *cur1 + *cur2;
        // insert
        auto scores_end = end(scores);
        while (sumcur > 0) {
            size_t digit = sumcur % 10;
            sumcur /= 10;
            scores.insert(scores_end, digit);
            if (digit == 1) {
                ++num_ones;
            }
        }
        // move
    }

    for (auto i : scores) {
        std::cout << i << " " << std::endl;
    }
}
