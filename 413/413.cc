// 413. Arithmetic Slices   QuestionEditorial Solution  My Submissions
// Total Accepted: 3968
// Total Submissions: 7403
// Difficulty: Medium
// Contributors: XiangyuLi926
// A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequence:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.

// 1, 1, 2, 5, 7

// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

// The function should return the number of arithmetic slices in the array A.


// Example:

// A = [1, 2, 3, 4]

// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
#include <iostream>
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }

        std::vector<int> continue_slice_length;
        std::vector<int>::const_iterator vector_iter_p = A.cbegin();
        auto vector_iter_s = vector_iter_p + 1;
        bool if_find = false; 
        unsigned int num_slice = 0, interval;

        while(1) {
            interval = *vector_iter_s - *vector_iter_p;
            if (*(vector_iter_s + 1) - *vector_iter_s == interval) {
                if_find = true;
                vector_iter_s++;
                while (*(vector_iter_s + 1) - *vector_iter_s == interval && 
                       vector_iter_s != A.cend()) {
                    vector_iter_s++;
                }
            }

            if (if_find)
            {
                if_find = false;
                continue_slice_length.push_back(vector_iter_s - vector_iter_p + 1);
                vector_iter_p = vector_iter_s;
                vector_iter_s +=1;
            }
            else {
                vector_iter_p++;
                vector_iter_s = vector_iter_p + 1;                
            }

            if (vector_iter_s == A.cend()) {
                break;
            }
        }

        for (int i = 0; i < continue_slice_length.size(); ++i) {
            num_slice += (continue_slice_length[i] - 1) * (continue_slice_length[i] - 2) / 2;
        }

        return num_slice;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> A{1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5};
    Solution sl;
    std::cout<<sl.numberOfArithmeticSlices(A)<<std::endl;
    return 0;
}

//思路在于找连续最长序列