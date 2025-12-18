class Solution {
public:
    long long reverse(int x){
        long long reversed_x = 0;
        while(x){
            reversed_x *= 10;
            reversed_x += x % 10;
            x /= 10;
        }
        return reversed_x;
    }
    bool isPalindrome(int x) {
        long long reversed_x = reverse(x);
        if(x < 0){
            return 0;
        }
        return x == reversed_x;
    }
};
