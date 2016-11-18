// #include <iostream>
// #include <vector>
// #include <map>
// #include <climits>
// #include <numeric>


// class Solution {
// public:
//     class State
//     {
//     public:
//         State(std::vector<int>::const_iterator iter, 
//               const int count)
//         {
//             _m_iter = iter;
//             _m_count = count;
//         }
//         bool operator<(const State& state) const {
//             if (_m_count == state._m_count)
//             {
//                 return state._m_iter < _m_iter;
//             }
//             return state._m_count < _m_count;
//         }
//         std::vector<int>::const_iterator _m_iter;
//         int _m_count;
//     };

//     int splitArray(std::vector<int>& nums, int m) {
//         std::map<State, unsigned int> value_record;

//         int min_sum = dp(nums, State(nums.cbegin(), 4), value_record);

//         return min_sum;
//     }

//     unsigned int dp(const std::vector<int>& nums,
//                     const State& state, 
//                     std::map<State, unsigned int>& value_record) {
//         if (value_record.find(state) != value_record.cend())
//         {
//             return value_record[state];
//         }

//         if (state._m_count == 0) {
//             unsigned int temp = std::accumulate(state._m_iter, nums.cend(), 0);
//             value_record[state] = temp;
//             return temp;
//         }

//         unsigned int max_sum = 0;
//         unsigned int min_max_sum = UINT_MAX;

//         for (std::vector<int>::const_iterator i = state._m_iter; i != nums.cend(); ++i)
//         {
//             max_sum = std::max(std::accumulate(nums.cbegin(), state._m_iter, 0), dp(nums, State(i + 1, state._m_count - 1), value_record));
//             min_max_sum = std::min(max_sum,min_max_sum);
//         }

//         value_record[state] = min_sum;
//         return min_sum;
//     }
// };

// int main(int argc, char const *argv[])
// {
//     std::vector<int> nums{7, 2, 5, 10, 8};
//     Solution sl;
//     std::cout<<sl.splitArray(nums, 2)<<std::endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <numeric>


class Solution {
public:
    int splitArray(std::vector<int>& nums, int m) {
        int max = std::max_element(nums.cbegin(), nums.cend());
        long sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        return BinarySearch(nums, m, sum, max);
    }
    long BinarySearch(const std::vector<int>& nums, 
                      const int count, 
                      const long sum, 
                      int max) {
        while()
    }
    unsigned int dp(const std::vector<int>& nums,
                    const State& state, 
                    std::map<State, unsigned int>& value_record) {
        if (value_record.find(state) != value_record.cend())
        {
            return value_record[state];
        }

        if (state._m_count == 0) {
            unsigned int temp = std::accumulate(state._m_iter, nums.cend(), 0);
            value_record[state] = temp;
            return temp;
        }

        unsigned int max_sum = 0;
        unsigned int min_max_sum = UINT_MAX;

        for (std::vector<int>::const_iterator i = state._m_iter; i != nums.cend(); ++i)
        {
            max_sum = std::max(std::accumulate(nums.cbegin(), state._m_iter, 0), dp(nums, State(i + 1, state._m_count - 1), value_record));
            min_max_sum = std::min(max_sum,min_max_sum);
        }

        value_record[state] = min_sum;
        return min_sum;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums{7, 2, 5, 10, 8};
    Solution sl;
    std::cout<<sl.splitArray(nums, 2)<<std::endl;
    return 0;
}