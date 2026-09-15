class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                string str = s.substr(j, i);
                if (isPalindrome(str)) {
                    count++;
                }
            }
        }

        return count;
    }
};
