class Solution {
public:
    int countComma(int n){
        int ans = 0;
        while(n/1000){
            n /= 1000;
            ans++;
        }
        return ans;
    }
    int countCommas(int n) {
        int ans = 0;
        int temp = countComma(n);
        while( temp ){
            ans += temp;
            n = n -1;
            temp = countComma(n);
        }

        return ans;
    }
};
