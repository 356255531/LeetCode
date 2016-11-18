// 451. Sort Characters By Frequency   QuestionEditorial Solution  My Submissions
// Total Accepted: 1891
// Total Submissions: 4171
// Difficulty: Medium
// Contributors: stickypens
// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

#include <iostream>
#include <string>
#include <map>
class Solution {
public:
    std::string frequencySort(std::string s) {
       std::map<char, int> hash_table; 
       for (std::string::const_iterator i = s.cbegin() ; i != s.cend(); ++i) {
           if (hash_table.find(*i) != hash_table.cend()) {
            hash_table[*i]++;
           }
           else
           {
            hash_table[*i] = 1;
           }
       }

        using pair_type = decltype(hash_table)::value_type;
        auto pr = std::max_element
        (
            std::begin(hash_table), std::end(hash_table),
            [] (const pair_type & p1, const pair_type & p2) {
                return p1.second < p2.second;
            }
        );

        char key;
        std::string output;

        for (int i = 0; i < hash_table.size(); ++i) {
            key = pr->first;
            std::cout<<'t'<<hash_table['t']<<std::endl;
            output.append(std::string(hash_table[key], key));
            hash_table[key] = 0;
            pr = std::max_element
            (
                std::begin(hash_table), std::end(hash_table),
                [] (const pair_type & p1, const pair_type & p2) {
                    return p1.second < p2.second;
                }
            );
        }
        std::cout<<output<<std::endl;
        return output;
    }
};

int main(int argc, char const *argv[]) {
    std::string input;
    std::cin>>input;
    std::cout<<input<<std::endl;
    Solution sl;
    std::cout<<sl.frequencySort(input)<<std::endl;
    return 0;
}