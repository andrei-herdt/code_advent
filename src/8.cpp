#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int sum_meta(vector<size_t>::iterator& it) {
    int num_children{*it++};
    int num_meta{*it++};
    int sumall{0};
    for (int i = 0; i < num_children; ++i) {
        sumall += sum_meta(it);
    }
    for (int i = 0; i < num_meta; ++i) {
        sumall += *it++;
    }
    return sumall;
}

int main() {
    ifstream input_file;
    input_file.open("../data/8.txt");

    string input;
    getline(input_file, input);
    stringstream numbers(input);
    size_t num;
    vector<size_t> tree_stream;
    while (numbers >> num) {
        tree_stream.push_back(num);
    };

    // Pass pointer by reference
    auto it{begin(tree_stream)};
    std::cout << sum_meta(it) << std::endl;
}
