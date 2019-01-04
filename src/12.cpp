#include <assert.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
    /* Get initial state
     * Update state 20 times
     *  for all pots look for match using regex
     * Sum up all plant containing pots
     */
    vector<string> rulesraw{
        "...## => #", "..#.. => #", ".#... => #", ".#.#. => #", ".#.## => #",
        ".##.. => #", ".#### => #", "#.#.# => #", "#.### => #", "##.#. => #",
        "##.## => #", "###.. => #", "###.# => #", "####. => #"};
    vector<pair<string, char>> rules;
    for (auto rule : rulesraw) {
        rules.push_back(make_pair(rule.substr(0, 5), rule.back()));
    }
    string stateraw{"#..#.#..##......###...###"};
    string state{stateraw};
    state.insert(begin(state), '.');
    state.insert(begin(state), '.');
    state.insert(begin(state), '.');
    state.insert(end(state), '.');
    state.insert(end(state), '.');
    state.insert(end(state), '.');

    auto statenew{state};
    for (int i = 0; i < stateraw.size(); ++i) {
        auto pots = state.substr(i + 1, 5);
        for (auto rule : rules) {
            if (rule.first == pots) {
                std::cout << "pots" << std::endl;
                std::cout << pots << std::endl;
                std::cout << "rule.first" << std::endl;
                std::cout << rule.first << std::endl;
                statenew[i + 3] = rule.second;
            } else {
                statenew[i + 3] = '.';
            }
        }
    }
    std::cout << statenew << std::endl;
}
