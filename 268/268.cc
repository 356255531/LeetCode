// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// For example,
// Given nums = [0, 1, 3] return 2.

// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(const std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            if (nums[0] == 1) {
                return 0;
            }
            else {
                return 1;
            }
        }

        std::vector<int> nums_copy(nums.size() + 1, -1);
        for(auto i = nums.cbegin(); i != nums.cend(); i++) {
            nums_copy[*i] = 0;
        }

        auto num_position = std::find_if(nums_copy.cbegin(), nums_copy.cend(), -1);
    //     if  (num_position != nums_copy.cend()) { 
    //         return num_position - nums_copy.cend();
    //     }
    //     else {
    //         return 0;
    //     }
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> nums{0, 1};
    Solution sl;
    std::cout<<sl.missingNumber(nums);
    return 0;
}