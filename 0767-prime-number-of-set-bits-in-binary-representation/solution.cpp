class Solution {
public:
    int count_set_bit(int n){
        int ans = 0;
        while(n){
            ans += n&1;
            n>>=1;
        }
        return ans;
    }
    bool is_prime(int n){
        if(n <= 1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++){
            int x = count_set_bit(i);
            if(is_prime(x)){
                ans++;
            }
        }
        return ans;
    }
};
