// 292. Nim Game 
// You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

// Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

// For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

// Hint:

// If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?

// 容易看出来，只有当出现了4的倍数，先手无可奈何，其余情况先手都可以获胜。
#include <iostream>
#include <vector>
// class Solution {  //DP solution too slow
// public:
//     bool canWinNim(int n) {
//         if (n < 1) return false;
//         if (n < 4) return true;
//         std::vector<bool> if_win(3, true);
//         for(int i = 4;i<=n;i++) {
//             bool if_win_n = false;
//             for(int j = 1;j<4;j++) {
//                 if (!if_win[i - j - 1]) {
//                     if_win_n = true;
//                     break;
//                 }
//             }
//             if_win.push_back(if_win_n);
//         }
//         return if_win[n - 1];
//     }
// };
class Solution {
public:
    bool canWinNim(int n) {
        return 0 != n % 4;
    }
};
int main(int argc, char const *argv[]) {
    Solution sl;
    std::cout<<sl.canWinNim(1348820612)<<std::endl;;
    return 0;
}