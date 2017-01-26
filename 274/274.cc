#include <iostream>
#include <vector>
#include <stdlib.h>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        if (0 == citations.size()) {
            return 0;
        }

        quick_sort(citations);
        for(auto i = citations.cbegin(); i != citations.cend();i++) {
            if ((i - citations.cbegin() + 1) >= *i) {
                return *i;
            }
        }
        return 0;
    }
private:
    void quick_sort(std::vector<int>& citations);
};

int main(int argc, char const *argv[]) {
    std::vector<int> citations;
    for (int i = 0; i < 100; ++i) {
        citations.push_back(std::rand()  % 100 + 1);
    }
    Solution sl;
    std::cout<<sl.hIndex(citations)<<std::endl;
    return 0;
}

void Solution::quick_sort(std::vector<int>& citations) {

}