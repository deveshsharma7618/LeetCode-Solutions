class Solution {
public:
    int reverse(int x) {
        int reverse_x = 0;
        while(x){
            int digit = x%10;
            if(reverse_x > INT_MAX/10 || reverse_x < INT_MIN/10){
                return 0;
            }

            reverse_x = reverse_x * 10 + digit;
            x /= 10;
        }
        return reverse_x;
    }
};
