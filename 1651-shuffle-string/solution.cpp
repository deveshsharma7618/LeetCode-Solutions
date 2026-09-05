class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, ' ');

        int j = 0;

        for(int i : indices){
            ans[i] = s[j];
            j++;
        }

        return ans;
    }
};
