class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ans;
        int carry = 0;
        int m = num1.size();
        int n = num2.size();

        int i = 0, j = 0;
        while( i < m && j < n){
            int sum = num1[i] + num2[j] - 2 * '0' + carry ;
            carry = sum/10;
            ans += sum%10 + '0';
            i++;
            j++;
        }

        while(i < m){
            int sum = num1[i] -'0' + carry;
            carry = sum/10;
            ans += sum%10 + '0';
            i++;
        }

        
        while(j < n){
            int sum = num2[j] -'0' + carry;
            carry = sum/10;
            ans += sum%10 + '0';
            j++;
        }

        while(carry){
            ans += carry%10 + '0';
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;



    }
};
