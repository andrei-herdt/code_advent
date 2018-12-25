#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "day_five_utils.h"

using namespace std;

int main() {
    ifstream input_file;
    input_file.open("../data/day_five.txt");

    string poly_full;
    getline(input_file, poly_full);
    string poly = poly_full;
    React(poly);
    cout << "size of string= " << poly.size() << endl;

    // Part two
    for (char chr = 'A'; chr <= 'Z'; ++chr) {
        poly = poly_full;
        std::cout << chr << "/" << chr + (char)32 << std::endl;
        poly.erase(remove(begin(poly), end(poly), chr), end(poly));
        poly.erase(remove(begin(poly), end(poly), chr + 32), end(poly));
        React(poly);
        cout << "size of string= " << poly.size() << endl;
    }

    // Part two
    return 0;
}
