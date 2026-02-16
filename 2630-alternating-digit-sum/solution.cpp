class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            sum += (i % 2 == 0) ? digit : -digit;
        }
        return sum;
    }
};
