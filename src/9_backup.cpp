#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

//@todo Implement with std::rotate

int main(int argc, char** argv) {
    int num_players = atoi(argv[1]);
    int last_marble = atoi(argv[2]);

    const vector<string> input{"10 players; last marble is worth 1618 points",
                               "13 players; last marble is worth 7999 points",
                               "17 players; last marble is worth 1104 points",
                               "21 players; last marble is worth 6111 points",
                               "30 players; last marble is worth 5807 points"};

    list<size_t> board;
    list<size_t>::iterator cur_pos{end(board)};

    vector<size_t> scores;
    scores.resize(num_players, 0);
    vector<size_t>::iterator cur_player{begin(scores)};

    board.insert(cur_pos, 0);
    for (int marble = 1; marble <= last_marble; ++marble) {
        // Evaluate
        if (marble % 23 == 0) {
            *cur_player += marble;
            for (int i = 0; i < 8; ++i) {
                if (cur_pos == begin(board)) {
                    cur_pos = end(board);
                }
                --cur_pos;
            }
            *cur_player += *cur_pos;
            cur_pos = board.erase(cur_pos);
        } else {
            // move one time
            if (cur_pos == end(board)) {
                cur_pos = begin(board);
            }
            ++cur_pos;

            // Insert marble
            board.insert(cur_pos, marble);
        }
        // next player
        ++cur_player;
        if (cur_player == end(scores)) {
            cur_player = begin(scores);
        }
    }

    for (auto i : board) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "scores: " << std::endl;
    for (auto i : scores) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
