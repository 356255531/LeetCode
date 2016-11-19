// 454. 4Sum II 

// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

// To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and 
// the result is guaranteed to be at most 231 - 1.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<long long, int> occur_map;
        long long count = 0;

        for(auto i = A.cbegin(); i != A.cend(); i++){
            for(auto j = B.cbegin(); j != B.cend(); j++){
                occur_map[*i + *j]++;
            }
        }

        for(auto i = C.cbegin(); i != C.cend(); i++){
            for(auto j = D.cbegin(); j != D.cend(); j++){
                count += occur_map[-*i - *j];
            }
        }
        return count;   
    }
};

// 这道题是之前那道4Sum的延伸，让我们在四个数组中各取一个数字，使其和为0。那么坠傻的方法就是遍历所有的情况，时间复杂度为O(n4)。
// 但是我们想想既然Two Sum那道都能将时间复杂度缩小一倍，那么这道题我们使用哈希表是否也能将时间复杂度降到O(n2)呢？
// 答案是肯定的，我们如果把A和B的两两之和都求出来，在哈希表中建立两数之和跟其出现次数之间的映射，那么我们再遍历C和D中任意两个数之和，
// 我们只要看哈希表存不存在这两数之和的相反数就行了.