#include <assert.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<size_t> scores{3, 7};

    size_t cur1{0};
    size_t cur2{1};
    size_t input = 824501;
    while (scores.size() < input + 10) {
        // gen new recipes
        size_t sumcur = scores[cur1] + scores[cur2];
        // insert
        if (sumcur >= 10) {
            scores.push_back(1);
        }
        scores.push_back(sumcur % 10);
        cur1 = (cur1 + scores[cur1] + 1) % scores.size();
        cur2 = (cur2 + scores[cur2] + 1) % scores.size();
    }

    auto it = begin(scores) + input;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << *it++;
    }
    std::cout << std::endl;
}
