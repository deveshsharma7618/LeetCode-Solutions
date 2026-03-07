class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int count = 0;
            int k = i;
            while(k){
                int bit = k&1;
                k >>= 1;
                if(bit){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
