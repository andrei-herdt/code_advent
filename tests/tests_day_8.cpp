#include <gmock/gmock.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <fstream>
#include <vector>

using namespace std;

TEST(day_8, part_one) {
    const string input{"2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2 "};
    //@todo use sstream to convert to size_t

    vector<size_t> tree(input.size() / 2);
    // for (int l = 0; l < input.size() / 2; ++l) {
    //     tree[l] = stoi(input[2 * l]);
    //     std::cout << tree[l] << " ";
    // }
    // std::cout << std::endl;
    // vector<pair<char, char>> dependencies(input.size());
    // for (size_t dep = 0; dep < input.size(); ++dep) {
    //     dependencies[dep] = pair<char, char>(input[dep][5], input[dep][36]);
    // }

    /* Create graph from data stream
     * traverse all nodes to gather the meta data
     */

    // typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS>
    //     Graph;

    // Graph G(dependencies.begin(), dependencies.end(), 6);

    // typedef std::vector<char> container;
    // container c;
    // topological_sort(G, std::back_inserter(c));

    // cout << "A topological ordering: ";
    // for (container::reverse_iterator ii = c.rbegin(); ii != c.rend(); ++ii)
    //     cout << *ii << " ";
    // cout << endl;
}
