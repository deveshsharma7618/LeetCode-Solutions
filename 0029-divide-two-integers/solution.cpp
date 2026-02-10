class Solution {
public:
    int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    if(dividend == INT_MAX && divisor == -1)
        return -INT_MAX;
        
    if(dividend == INT_MAX && divisor == 1)
        return INT_MAX;

    bool neg = (dividend < 0) ^ (divisor < 0);

    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);

    long long q = 0;
    while (a >= b) {
        a -= b;
        q++;
    }

    return neg ? -q : q;
    }
};
