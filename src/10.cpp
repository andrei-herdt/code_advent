#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

void UpdatePositions(vector<pair<int, int>> positions,
                     vector<pair<int, int>> velocities) {
    for (int i = 0; i < positions.size(); ++i) {
        positions[i].first += velocities[i].first;
        positions[i].second += velocities[i].second;
    }
}

int main() {
    const vector<string> input{"position=< 9,  1> velocity=< 0,  2>",
                               "position=< 7,  0> velocity=<-1,  0>",
                               "position=< 3, -2> velocity=<-1,  1>",
                               "position=< 6, 10> velocity=<-2, -1>",
                               "position=< 2, -4> velocity=< 2,  2>",
                               "position=<-6, 10> velocity=< 2, -2>",
                               "position=< 1,  8> velocity=< 1, -1>",
                               "position=< 1,  7> velocity=< 1,  0>",
                               "position=<-3, 11> velocity=< 1, -2>",
                               "position=< 7,  6> velocity=<-1, -1>",
                               "position=<-2,  3> velocity=< 1,  0>",
                               "position=<-4,  3> velocity=< 2,  0>",
                               "position=<10, -3> velocity=<-1,  1>",
                               "position=< 5, 11> velocity=< 1, -2>",
                               "position=< 4,  7> velocity=< 0, -1>",
                               "position=< 8, -2> velocity=< 0,  1>",
                               "position=<15,  0> velocity=<-2,  0>",
                               "position=< 1,  6> velocity=< 1,  0>",
                               "position=< 8,  9> velocity=< 0, -1>",
                               "position=< 3,  3> velocity=<-1,  1>",
                               "position=< 0,  5> velocity=< 0, -1>",
                               "position=<-2,  2> velocity=< 2,  0>",
                               "position=< 5, -2> velocity=< 1,  2>",
                               "position=< 1,  4> velocity=< 2,  1>",
                               "position=<-2,  7> velocity=< 2, -2>",
                               "position=< 3,  6> velocity=<-1, -1>",
                               "position=< 5,  0> velocity=< 1,  0>",
                               "position=<-6,  0> velocity=< 2,  0>",
                               "position=< 5,  9> velocity=< 1, -2>",
                               "position=<14,  7> velocity=<-2,  0>",
                               "position=<-3,  6> velocity=< 2, -1>"};

    vector<pair<int, int>> positions(input.size());
    vector<pair<int, int>> velocities(input.size());

    std::regex id_regex("-*[0-9]+");
    for (int i = 0; i < input.size(); ++i) {
        auto words_begin =
            std::sregex_iterator(input[i].begin(), input[i].end(), id_regex);
        auto words_end = std::sregex_iterator();
        vector<int> numbers;
        for (auto it = words_begin; it != words_end; ++it) {
            std::smatch match = *it;
            numbers.push_back(stoi(match.str()));
        }
        positions[i] = make_pair(numbers[0], numbers[1]);
        velocities[i] = make_pair(numbers[2], numbers[3]);
    }

    UpdatePositions(positions, velocities);
    UpdatePositions(positions, velocities);
    UpdatePositions(positions, velocities);
    for (auto i : positions) {
        std::cout << i.first << " " << i.second;
        std::cout << std::endl;
    }

    // std::cout << "scores: " << std::endl;
    // for (auto i : scores) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;
}
