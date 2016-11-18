#include <iostream>
#include <vector>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        if (nums.size() < 2) {
            return false;
        }
        for (std::vector<int>::const_iterator i = nums.cbegin(); i != nums.cend() - 1; ++i) {
            for (std::vector<int>::const_iterator j = i + 1; j != nums.cend(); ++j) {
                if (j - i > k) {
                    break;
                }

                auto distance = [](double x, double y) {
                    double distance = x - y;
                    return (distance > 0) ? distance : 
                                            -distance;
                };
                if (distance(static_cast<double>(*i), 
                             static_cast<double>(*j)) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};