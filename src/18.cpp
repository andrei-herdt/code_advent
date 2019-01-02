#include <assert.h>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
    // Construct acre

    auto tracre = [](char acre) {
        // An open acre will become filled with trees if three or more adjacent
        // acres contained trees. Otherwise, nothing happens.

        //     An acre filled with trees will become a lumberyard if three or
        //     more adjacent acres were lumberyards. Otherwise, nothing happens.

        //     An acre containing a lumberyard will remain a lumberyard if it
        //     was adjacent to at least one other lumberyard and at least one
        //     acre containing trees. Otherwise, it becomes open.
    };

    // Give adjacent fields as container

    // count adjacent fields

    // for (auto i : scores) {
    //     std::cout << i << " " << std::endl;
    // }
}
