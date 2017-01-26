// 279. Perfect Squares  
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
// 如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x=a+bｘb，那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。
#include <iostream>
#include <math.h>
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        int least_num_perfect[n];
        for (int i = 0; i < n; ++i) {
            least_num_perfect[i] = n+1;
        }
        for (int i = 1; i * i <= n; ++i) {
            least_num_perfect[i * i - 1] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j * j + i <= n; ++j) {
                least_num_perfect[i + j * j - 1] = fmin(
                    least_num_perfect[i + j * j - 1], 
                    least_num_perfect[i - 1] + 1
                );
            }
        }
        return least_num_perfect[n - 1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sl;
    std::cout<<sl.numSquares(4)<<std::endl;
    return 0;
}