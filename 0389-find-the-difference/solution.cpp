class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        int m = s.size();
        int n = t.size();
        if(m > n){
            return findTheDifference(t,s);
        }else{
            for(int i=0; i < m; i++){
                ans ^= s[i];
                ans ^= t[i];
            }
            
            ans ^= t[m];
            return ans;
        }
    }
};
