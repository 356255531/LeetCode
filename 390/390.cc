#include <math.h>
#include <iostream>
#include <vector>
class Solution {
public:
    int lastRemaining(int n) {
        std::vector<bool> array(n, true);
        int round = int(log2(n - 1));
        for (int i = 0; i < round; ++i) {
            int indicator = i / 2 == 0? 0 : n - 1;
            bool eliminate = true, direction = i / 2 == 0? true : false;
            while(indicator != -1 and indicator != n) {
                if (direction) {
                    if (array[indicator]) {
                        if (eliminate) {
                            array[indicator] = false;
                            eliminate = false;
                            indicator++;
                        }
                        else {
                            eliminate = true;
                            indicator++;
                        }
                    }
                    else {
                        indicator++;
                    }
                }
                else {
                    if (array[indicator]) {
                        if (eliminate) {
                            array[indicator] = false;
                            eliminate = false;
                            indicator--;
                        }
                        else {
                            eliminate = true;
                            indicator--;
                        }
                    }
                    else {
                        indicator--;
                    }
                }

            }
        }
        for (int i = 0; i < n; ++i) {
            if (array[i]) {
                int answer = i + 1;
                return answer;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sl;
    std::cout<<sl.lastRemaining(24)<<std::endl;
    return 0;
}