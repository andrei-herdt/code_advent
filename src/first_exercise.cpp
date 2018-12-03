#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::ifstream input_file;
    input_file.open("../data/first_day.txt");

    int number;
    std::vector<int> frequencies;
    while (input_file >> number) {
        frequencies.push_back(number);
    }
    int sum = std::accumulate(frequencies.begin(), frequencies.end(), 0);
    std::cout << "The resulting frequency is: " << sum << std::endl;

    return 0;
}
