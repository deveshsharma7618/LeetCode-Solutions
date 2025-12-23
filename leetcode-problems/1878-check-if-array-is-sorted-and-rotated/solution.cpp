class Solution {
public:
    bool is_sorted(vector<int> &s, int i){
        int n = s.size();
        for(int j = 0; j < n-1; j++){
            if(s[(j+i) % n] > s[(j+i+1) % n]){
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(is_sorted(nums,i)){
                return true;
            }
        }
        return false;
    }
};
