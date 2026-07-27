class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int i = 0;
        int n = s.size();
        string ans = "";
        int j = n-1;
        
        for(int i=0;i<n;i++){
            if( isalpha(s[i])){
                while(j >= 0 && !isalpha(s[j])){
                    j--;
                }
                
                ans.push_back(s[j]);
                j--;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
