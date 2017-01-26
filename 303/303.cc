#include <iostream>
#include <vector>
class NumArray {
public:
    NumArray(std::vector<int> nums):num_array(nums) {
        length = nums.size();
        sum.push_back(nums[0]);
        for (int i = 1; i < length; ++i) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (length == 0) {
            return 0;
        }
        int sum_range = sum[j] - sum[i - 1];
        return sum_range;
    }
private:
    std::vector<int> num_array;
    int length;
    std::vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

 int main(int argc, char const *argv[]) {
    std::vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    std::cout<<obj->sumRange(2,5)<<std::endl;;
    return 0;
 }