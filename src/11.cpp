#include <assert.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
    int serial_number{0};
    auto power_level = [&serial_number](size_t x, size_t y) {
        int rack_id = x + 10;
        int pl = rack_id * y;
        pl += serial_number;
        pl *= rack_id;
        pl = (pl / 100) % 10;
        pl -= 5;
        return pl;
    };

    serial_number = 8;
    assert(power_level(3, 5) == 4);
    serial_number = 57;
    assert(power_level(122, 79) == -5);
    serial_number = 39;
    assert(power_level(217, 196) == 0);
    serial_number = 71;
    assert(power_level(101, 153) == 4);

    /*Generate map
     * Compute are sizes for 3x3 squares
     * Pick the biggest
     */
}
