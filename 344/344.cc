#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseString(std::string s) {
        std::string return_string(s.rbegin(), s.rend());
        return return_string;
    }
};

int main(int argc, char const *argv[]) {
    std::string s{"hello"};
    Solution sl;
    std::cout<<sl.reverseString(s);
    return 0;
}