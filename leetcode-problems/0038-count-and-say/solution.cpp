class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }else{
            string s = countAndSay(n-1);
            int i = 0;
            string ans;
            int freq = 1;
            while( i < s.size()-1){
                if(s[i] == s[i+1]){
                    freq++;
                }else{
                    string temp;
                    while(freq){
                        temp += freq%10 + '0';
                        freq /= 10;
                    }
                    reverse(temp.begin(),temp.end());
                    ans += temp;
                    ans += s[i];
                    freq = 1;
                }
                i++;
            }
            string temp;
            while(freq){
                temp += freq%10 + '0';
                freq /= 10;
            }
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans += s[i];
            return ans;
        }
    }
};
