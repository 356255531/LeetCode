// 371. Sum of Two Integers 
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example:
// Given a = 1 and b = 2, return 3.

class Solution { //bit operation
public:
    int getSum(int a, int b) {
        while(0 != b) {
            int c = a ^ b;
            b = (b & a) << 1;
            a = c;
        }
        return a;
    }
};


class Solution { // bit wise
public:
    int getSum(int a, int b) {
        int output = 0, carry = 0;
        for(int i = 0;i < 32;i++, a >>= 1, b >>= 1) {
            int low_a = a & 1, low_b = b & 1;
            output |= (low_a ^ low_b ^ carry) << i;
            carry = (low_a & carry) || (low_b & carry) || (low_a & low_b);
        }
        return output;
    }
};
