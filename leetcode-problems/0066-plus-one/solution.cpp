class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x = digits.size()-1;
        int carry = 0;
        int y = digits[x]+1;
        digits[x] = y%10;
        carry = y/10;
        x--;
        while(carry > 0 && x >= 0){
            y = digits[x]+carry;
            digits[x] = y%10;
            carry = y/10;
            x--;
        }

        if(carry != 0){
            digits.insert(digits.begin(),carry%10);
            carry /= 10;
        }

        return digits;
        
    }
};
