// 189. Rotate Array  
// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

// [show hint]

// Hint:
// Could you do it in-place with O(1) extra space?
// Related problem: Reverse Words in a String II

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        k %= nums.size();
        if (0 == k) return;
        
        reverse(nums.begin(), nums.end() - 1);
        reverse(nums.begin(), nums.begin() + k - 1);
        reverse(nums.begin() + k, nums.end() - 1);
    }
    void reverse(vector<int>::iterator a, vector<int>::iterator b) {
        int size = distance(a, b) + 1;
        for (int i = 0;i < size / 2;i++, a++, b--) {
            swap(*a, *b);
        }
    }
};