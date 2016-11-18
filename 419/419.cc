// Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
// Example:
// X..X
// ...X
// ...X
// In the above board there are 2 battleships.
// Invalid Example:
// ...X
// XXXX
// ...X
// This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
// Follow up:
// Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    int countBattleships(const std::vector<std::vector<char>>& board) {
        if (board.size() == 0) {
            return 0;
        }

        std::vector<int> record;
        int ship_count = 1, line_length = board[0].size();
        for (auto i = board.cbegin(); i != board.cend(); ++i) {
            for (auto j = (*i).cbegin(); j != (*i).cend(); ++j) {
                if ( *j == '.') {
                    record.push_back(0);
                    continue;
                }

                int index = record.size();
                int y_index = index / line_length;
                int x_index = index % line_length;

                if (0 < y_index) {
                    if (record[index - line_length] != 0) {
                        record.push_back(record[index - line_length]);
                        continue;
                    }
                }

                if (x_index > 0) {
                    if (record[index - 1] != 0) {
                        record.push_back(record[index - 1]);
                        continue;
                    }
                }

                record.push_back(ship_count);
                ship_count++;
            }
        }

        return *std::max_element(std::begin(record), std::end(record));
    }
};

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> board;
    int count = 3;
    while(count) {
        std::string input;
        std::cin>>input;
        std::vector<char> input_vector(input.cbegin(), input.cend());
        board.push_back(input_vector);
        input_vector.clear();
        count--;
    }
    std::cout<<std::endl;
    std::cout<<"Input is:"<<std::endl;
    for (auto i = board.cbegin(); i != board.cend();++i) {
        for(auto j = (*i).cbegin();j != (*i).cend();++j) {
            std::cout<< *j;
        }
        std::cout<<std::endl;
    }
    Solution sl;
    std::cout<<sl.countBattleships(board)<<std::endl;
    return 0;
}