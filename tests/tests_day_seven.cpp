#include <gmock/gmock.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

vector<char> LexicographicalTopologicalSort(const vector<string>& input,
                                            size_t num_symbols) {
    vector<pair<char, char>> dependencies(input.size());
    for (size_t dep = 0; dep < input.size(); ++dep) {
        dependencies[dep] = pair<char, char>(input[dep][5], input[dep][36]);
    }

    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS>
        Graph;

    Graph G(dependencies.begin(), dependencies.end(), num_symbols);

    typedef std::vector<char> container;
    container c;
    topological_sort(G, std::back_inserter(c));

    vector<char> t_sorted;
    container::reverse_iterator ii = c.rbegin();
    for (int i = 0; i < num_symbols; ++i) {
        t_sorted.push_back(*ii);
        ++ii;
    }

    bool sorting_incomplete{true};
    while (sorting_incomplete) {
        sorting_incomplete = false;
        for (size_t i = 0; i < t_sorted.size() - 1; ++i) {
            std::cout << t_sorted[i] << " " << t_sorted[i + 1] << std::endl;
            if ((t_sorted[i] > t_sorted[i + 1]) &&
                (find(begin(dependencies), end(dependencies),
                      make_pair(t_sorted[i], t_sorted[i + 1])) ==
                 end(dependencies))) {
                std::cout << t_sorted[i] << "<->" << t_sorted[i + 1]
                          << std::endl;
                swap(t_sorted[i], t_sorted[i + 1]);
                sorting_incomplete = true;
            }
        }
    }
    return t_sorted;
}

TEST(day_seven, part_one) {
    const vector<string> input{
        "Step C must be finished before step A can begin.",
        "Step C must be finished before step F can begin.",
        "Step A must be finished before step B can begin.",
        "Step A must be finished before step D can begin.",
        "Step B must be finished before step E can begin.",
        "Step D must be finished before step E can begin.",
        "Step F must be finished before step E can begin."};
    auto sorted_vector = LexicographicalTopologicalSort(input, 6);
    for (auto i : sorted_vector) {
        std::cout << i;
    }
    std::cout << std::endl;
}

TEST(day_seven, part_one_data) {
    ifstream input_file;
    input_file.open("../../data/day_seven.txt");

    vector<string> input;
    string word;
    while (getline(input_file, word)) {
        input.push_back(word);
    }
    auto sorted_vector = LexicographicalTopologicalSort(input, 26);
    for (auto i : sorted_vector) {
        std::cout << i;
    }
    std::cout << std::endl;
}
