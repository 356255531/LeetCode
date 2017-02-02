// 219. Contains Duplicate II
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

// Subscribe to see which companies asked this question


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        
        unordered_map<int, int> distance;
        for(int i = 0;i < nums.size();i++) {
            if (distance.find(nums[i]) != distance.end() && i - distance[nums[i]] <= k) return true;
            else distance[nums[i]] = i;
        }
        
        return false;
    }
};