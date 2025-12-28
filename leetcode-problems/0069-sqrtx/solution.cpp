class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        for(long long i=0;i*i <= (long long)x; i++)
            ans = i;
        return ans;
    }
};
