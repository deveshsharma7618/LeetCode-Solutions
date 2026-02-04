class Solution {
public:
    string commonPrefix(const string& a, const string& b) {
        int len = min(a.size(), b.size());
        int i = 0;
        while (i < len && a[i] == b[i]) {
            i++;
        }
        return a.substr(0, i);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix.empty())
                break;
        }
        return prefix;
    }
};
