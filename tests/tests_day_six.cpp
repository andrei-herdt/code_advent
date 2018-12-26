#include <gmock/gmock.h>
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>

#include <fstream>
#include "day_three_utils.h"

using namespace std;

const size_t kUndefined{1000000};

pair<size_t, size_t> ComputeBiggestArea(std::vector<string> input) {
    vector<size_t> x_positions(input.size(), 0);
    vector<size_t> y_positions(input.size(), 0);
    for (size_t id = 0; id < input.size(); ++id) {
        size_t comma = input[id].find(',');
        x_positions[id] = stoi(input[id].substr(0, comma));
        y_positions[id] = stoi(input[id].substr(comma + 1));
    }

    /* Make a map<pos, id>
     * Find boundaries of map
     * Fill in entire map with closest ids or -1
     * Remove id that are not closed
     * count number of other ids
     * take the max
     */
    map<std::pair<size_t, size_t>, size_t> coordinates;
    for (size_t id = 0; id < input.size(); ++id) {
        auto pos = make_pair(x_positions[id], y_positions[id]);
        coordinates[pos] = id;
    }
    size_t x_min = *min_element(begin(x_positions), end(x_positions));
    size_t x_max = *max_element(begin(x_positions), end(x_positions));
    size_t y_min = *min_element(begin(y_positions), end(y_positions));
    size_t y_max = *max_element(begin(y_positions), end(y_positions));
    for (size_t x = x_min; x <= x_max; ++x) {
        for (size_t y = y_min; y <= y_max; ++y) {
            // Compute closest id
            vector<size_t> distances(input.size(), 0);
            for (size_t id = 0; id < input.size(); ++id) {
                // Compute distance
                distances[id] = abs(static_cast<int>(x - x_positions[id])) +
                                abs(static_cast<int>(y - y_positions[id]));
            }
            auto min_distance = min_element(begin(distances), end(distances));
            size_t closest_id = kUndefined;
            if (count(begin(distances), end(distances), *min_distance) == 1) {
                closest_id = distance(begin(distances), min_distance);
            }
            coordinates[make_pair(x, y)] = closest_id;
        }
    }

    /* Remove ids from list of valid ids that are at the boundary*/
    vector<size_t> closed_ids(input.size());
    iota(begin(closed_ids), end(closed_ids), 0);
    for (size_t x = x_min; x <= x_max; ++x) {
        size_t id_bottom = coordinates[make_pair(x, y_min)];
        size_t id_top = coordinates[make_pair(x, y_max)];
        closed_ids.erase(remove(begin(closed_ids), end(closed_ids), id_bottom),
                         end(closed_ids));
        closed_ids.erase(remove(begin(closed_ids), end(closed_ids), id_top),
                         end(closed_ids));
    }

    map<size_t, size_t> closed_ids_count;
    for (auto it = begin(coordinates); it != end(coordinates); ++it) {
        if (find(begin(closed_ids), end(closed_ids), it->second) !=
            end(closed_ids)) {
            ++closed_ids_count[it->second];
        }
    }

    size_t max_count{0};
    for (auto it = begin(closed_ids_count); it != end(closed_ids_count); ++it) {
        max_count = max(max_count, it->second);
    }

    // Part B
    size_t safe_area_size{0};
    for (size_t x = x_min; x <= x_max; ++x) {
        for (size_t y = y_min; y <= y_max; ++y) {
            vector<size_t> distances(input.size(), 0);
            for (size_t id = 0; id < input.size(); ++id) {
                // Compute distance
                distances[id] = abs(static_cast<int>(x - x_positions[id])) +
                                abs(static_cast<int>(y - y_positions[id]));
            }
            if (accumulate(begin(distances), end(distances), 0) < 10000) {
                safe_area_size++;
            }
        }
    }
    return make_pair(max_count, safe_area_size);
}

TEST(day_six, part_one) {
    const vector<string> input{"1, 1", "1, 6", "8, 3", "3, 4", "5, 5", "8, 9"};

    ASSERT_EQ(ComputeBiggestArea(input).first, 17);
}

TEST(day_six, part_one_two) {
    ifstream input_file;
    input_file.open("../../data/day_six.txt");

    vector<string> input;
    string word;
    while (getline(input_file, word)) {
        input.push_back(word);
    }
    auto [part_one, part_two] = ComputeBiggestArea(input);
    std::cout << part_one << std::endl;
    std::cout << part_two << std::endl;
}
