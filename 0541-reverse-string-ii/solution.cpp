class Solution {
public:
    string reverseStr(string s, int k) {

        int n = s.size();
        for(int i = 0; i < n; i += 2*k){
            if( n - i >= k && n - i < 2 * k){
                reverse(s.begin()+i, s.begin() + i + k);
            }else if( n - i < k){
                reverse(s.begin() + i, s.end());
            }else{
                reverse(s.begin() + i, s.begin() + k + i);
            }

        }

        return s;
    }
};
