class Solution {
public:
    bool isPalindrome(string s) {
        string k;
        for(int i= 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                k += s[i] - 'A' + 'a';
            }else if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')){
                k += s[i];
            }
        }

        int i = 0, j = k.size()-1;
        while(i<=j){
            if(k[i] != k[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};
