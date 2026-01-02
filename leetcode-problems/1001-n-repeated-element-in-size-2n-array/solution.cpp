class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int freq[100001] = {0};
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<100001;i++){
            if(freq[i] == nums.size()/2){
                return i;
            }
        }
        return -1;
    }
};
