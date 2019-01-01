#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int sum_meta(vector<size_t>::iterator it) {
    ++it;
    int num_meta = *it;
    int sum_meta{0};
    for (int i = 0; i < num_meta; ++i) {
        ++it;
        sum_meta += *it;
    }
    return sum_meta;
}

int main() {
    const string input{"2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2 "};
    //@todo use sstream to convert to size_t
    stringstream numbers(input);
    size_t num;
    vector<size_t> tree_stream;
    while (numbers >> num) {
        tree_stream.push_back(num);
    };

    std::cout << sum_meta(begin(tree_stream)) << std::endl;

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
    // for (container::reverse_iterator ii = c.rbegin(); ii != c.rend();
    // ++ii)
    //     cout << *ii << " ";
    // cout << endl;
}
