// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return std::string{""};
        }
        if (strs.size() == 1) {
            return *(strs.cbegin());
        }

        std::string common_prefix_string{""};
        unsigned int count = 0;
        char chr;
        while(1) {
            chr = (*strs.cbegin())[count];
            for (auto i = strs.cbegin() + 1; i != strs.cend(); ++i) {
                if (chr != (*i)[count] or count > (*i).size()) {
                    return common_prefix_string;
                }
            }
            common_prefix_string.push_back(chr);
            count++;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sl;
    std::vector<std::string> strs{"fuck"};
    std::cout<<sl.longestCommonPrefix(strs)<<std::endl;
    return 0;
}