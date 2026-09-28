class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }else if( s[i] == ')'){
                ans = ans > st.size() ? ans : st.size();
                st.pop();
            }
        }

        return ans;
    }
};
