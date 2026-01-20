class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int x = a.size();
        int y = b.size();
        int i = 0;
        string ans = "";
        int carry = 0;
        while(i < x && i < y){
            int a1 = a[i]-'0';
            int b1 = b[i]-'0';
            ans += a1^b1^carry + '0';
            carry = (a1 & b1) | ((a1|b1)&carry);
            i++;
        }

        while(i < x){
            int bit = a[i]-'0';
            ans += (bit)^carry + '0';
            carry = (bit) & carry;
            i++;
        }

        while(i < y){
            int bit = b[i]-'0';
            ans += (bit)^carry + '0';
            carry = (bit) & carry;
            i++;
        }
        
        if(carry){
            ans += "1";
        }
            
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
