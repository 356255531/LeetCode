// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.
#include <iostream>
#include <vector>
#include <map>
#include <numeric>

class Solution {
public:
    class State
    {
    public:
        State(const std::vector<int>::const_iterator& iter,
                          const int rest_sum) {
            _m_rest_sum = rest_sum;
            _m_iter = iter;
        }

        bool operator < (const State& state) const
        {
            if (state._m_iter < _m_iter && 
                state._m_rest_sum == _m_rest_sum) {
                return true;
            }
            return state._m_rest_sum < _m_rest_sum;
        }

        int _m_rest_sum;
        std::vector<int>::const_iterator _m_iter;
    };

    bool canPartition(std::vector<int>& nums) {
        int sum_array = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum_array & 1) {
            return false;
        }

        std::map<State, bool> subresult_array;
        return if_subset_found(State(nums.cend(), sum_array / 2), subresult_array, nums);
    }

    bool if_subset_found(const State& state,
                         std::map<State, bool>& subresult_array, 
                         const std::vector<int>& nums) {
        if (subresult_array.find(state) != subresult_array.end()) {
            if (subresult_array[state]) {
                return true;
            }
            else {
                return false;
            }
        }

        if (std::accumulate(nums.cbegin(), state._m_iter, 0) < state._m_rest_sum ||
            state._m_rest_sum < 0)
        {
            subresult_array[state] = false;
            return false;
        }

        if (*(state._m_iter - 1) == state._m_rest_sum)
        {
            subresult_array[state] = true;
            return true;
        }

        for (std::vector<int>::const_iterator i = state._m_iter - 1; i != nums.cbegin(); --i) {
            State temp_state(i, state._m_rest_sum - *i);
            if (if_subset_found(temp_state, subresult_array, nums)) {
                subresult_array[temp_state] = true;
                return true;
            }
            else {
                subresult_array[state] = false;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums{1, 5, 11, 5};
    Solution sl;
    if (sl.canPartition(nums))
    {
        std::cout<<"pass"<<std::endl;
    }
    else {
        std::cout<<"fail"<<std::endl;
    }
    return 0;
}