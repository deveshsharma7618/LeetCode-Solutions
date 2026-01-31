class Solution {
public:
    bool is_palindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (is_palindrome(s, i, j)) {
                    if (j - i > end - start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        string ans;
        while (start <= end) {
            ans += s[start++];
        }
        return ans;
    }
};
