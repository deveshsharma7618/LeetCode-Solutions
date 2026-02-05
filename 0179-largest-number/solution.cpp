class Solution {
public:
    static bool compare(const string& a, const string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int x : nums) {
            s.push_back(to_string(x));
        }

        sort(s.begin(), s.end(), compare);

        // Edge case: all zeros
        if (s[0] == "0") return "0";

        string ans;
        for (const string& str : s) {
            ans += str;
        }

        return ans;
    }
};
