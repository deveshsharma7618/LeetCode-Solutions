class Solution {
public:
    int count_digits(int x){
        int count = 0;
        while(x){
            count++;
            x /= 10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            if(count_digits(x)%2 == 0){
                ans++;
            }
        }
        return ans;
    }
};
