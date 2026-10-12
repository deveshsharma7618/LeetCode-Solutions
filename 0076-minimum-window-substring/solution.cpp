class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        vector<int> mp(128, 0);
        for (char c : t) {
            mp[c]++;
        }

        int start = 0, end = 0, count = t.size();
        int minLen = INT_MAX, head = 0;

        while (end < s.size()) {
            if (mp[s[end]] > 0) {
                count--;
            }
            mp[s[end]]--;
            end++;

            while (count == 0) {
                if (end - start < minLen) {
                    minLen = end - start;
                    head = start;
                }

                mp[s[start]]++;
                if (mp[s[start]] > 0) {
                    count++;
                }
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};
