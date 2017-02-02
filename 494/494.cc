// 494. Target Sum

// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:

    class num_pair {
    public:
        vector<int>::iterator index;
        int sum;
        num_pair(vector<int>::iterator idx, int s):index(idx), sum(s) {}
        bool operator<(const num_pair& next) const {
            if (next.sum < sum) return true;
            else {
                if (next.sum == sum && *next.index < *index) return true;
            }
            return false;
        }
    };

    map<num_pair, int> num_map;

    int findTargetSumWays(vector<int>& nums, int S) {
        int num = find_target_num(nums.begin(), nums.end(), S);
        return num;
    }
    int find_target_num(vector<int>::iterator a, vector<int>::iterator b, int sum) {
        if (0 == distance(a, b)) {
            if (0 == sum) {
                num_map[num_pair(a, sum)] = 1;
                return 1;
            }
            else {
                num_map[num_pair(a, sum)] = 0;
                return 0;
            }
        }
        
        if (1 == distance(a, b)) {
            if (0 == *a  || *a == sum) {
                num_map[num_pair(a, sum)] = 2;
                return 2;
            }
            if (sum == *a || sum == -*a) {
                num_map[num_pair(a, sum)] = 1;
                return 1;
            }
            num_map[num_pair(a, sum)] = 0;
            return 0;
        }
        
        num_pair pair_1 = num_pair(a + 1, sum - *a);
        num_pair pair_2 = num_pair(a + 1, sum + *a);
        if (num_map.find(pair_1) == num_map.end()) num_map[pair_1] = find_target_num(a + 1, b, sum - *a);
        if (num_map.find(pair_2) == num_map.end()) num_map[pair_2] = find_target_num(a + 1, b, sum + *a);
        
        num_pair this_pair = num_pair(a, sum);
        num_map[this_pair] = num_map[pair_1] + num_map[pair_2];
        
        return num_map[this_pair];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> fuck(5, 1);
    Solution sl;
    cout<<sl.findTargetSumWays(fuck, 1);
    return 0;
}