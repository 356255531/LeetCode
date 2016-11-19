// 217. Contains Duplicate   QuestionEditorial Solution  My Submissions
// Total Accepted: 127448
// Total Submissions: 295175
// Difficulty: Easy
// Contributors: Admin
// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <vector>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        if (nums.size() < 2) return false;
        
        auto max_num = std::max_element(nums.cbegin(), nums.cend());
        auto min_num = std::min_element(nums.cbegin(), nums.cend());

        if (max_num == min_num) {
            return true;
        }
        
        std::vector<int> if_duplicate(*max_num - *min_num, 0);
        for(auto i = nums.cbegin(); i != nums.cend(); i++) {
            if (if_duplicate[*i - *min_num] == 1) return true;
            if_duplicate[*i - *min_num] = 1;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> nums{3, 3};
    Solution sl;
    std::cout<<sl.containsDuplicate(nums);
    return 0;
}