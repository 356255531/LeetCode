// 136. Single Number

// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Subscribe to see which companies asked this question

// Hide Tags Hash Table Bit Manipulation
// Show Similar Problems
// Have you met this question in a real interview? No

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int output = 0;
        for(auto i = nums.cbegin();i!=nums.cend();i++) {
            output ^= *i;
        }
        return output;
    }
};