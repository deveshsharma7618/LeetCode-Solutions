class Solution {
public:
    int sumDigitSquare(int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum += digit*digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        if(n == 1){
            return true;
        }
        s.insert(n);
        do{
            int x = sumDigitSquare(n);
            if(s.count(x)){
                return false;
            }
            s.insert(x);
            n = x;
        }while(n != 1);
        return true;
    }
};
