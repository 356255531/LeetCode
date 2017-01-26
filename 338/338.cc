// 338. Counting Bits 
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> output_array(1, 0);   

        if (0 == num) {
            return output_array;
        } 

        for (int i = 1; i < num + 1; ++i) {
            int diff = judge_differ(i);
            if (1 == diff) {
                output_array.push_back(output_array[i - 1] + 1);            }
            else {
                output_array.push_back(output_array[i - 1] - diff + 2);
            }
        }
        return output_array;
    }
    int judge_differ(int& i) {
        int diff_itg = i ^ (i - 1);
        int count = 0;
        while(diff_itg != 0) {
            count++;
            diff_itg >>= 1;
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution sl;
    for (int i = 0; i < 6; ++i) {
        std::cout<<sl.countBits(5)[i]<<std::endl;
    }
    return 0;
}