class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        vector<int> v(n,0);

        for(int i =0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(!st.empty()){
                int x = st.top();
                st.pop();

                v[x] = 1;
                v[i] = 1;
            }
        }

        int maxi = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(v[i] == 1){
                count++;
            }else{
                maxi = max(count,maxi);
                count = 0;
            }
        }
        maxi = max(count,maxi);
        return maxi;
    }
};
