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
    size_t num_ones = 0;
    for (int i = 0; i < 10; ++i) {
        // gen new recipes
        size_t sumcur = scores[cur1] + scores[cur2];
        // insert
        vector<size_t> digits;
        while (sumcur > 0) {
            size_t digit = sumcur % 10;
            digits.push_back(digit);
            sumcur /= 10;
            if (digit == 1) {
                ++num_ones;
            }
        }
        for (int i = 0; i < digits.size(); ++i) {
            scores.push_back(digits.pop_back());
        }
        // move
    }

    for (auto i : scores) {
        std::cout << i << " " << std::endl;
    }
}
