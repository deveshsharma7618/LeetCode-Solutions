class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;


        while (nums.size() > 0) {
            unordered_map<int, int> mp;
            for (int i = 0; i < nums.size(); i++) {
                mp[nums[i]] = i;
            }

            vector<int> temp;
            for (auto [key, value] : mp) {
                temp.push_back(key);
                nums[value] = -1;
            }

            for(int i = 0; i < nums.size(); i++){
                if( nums[i] == -1){
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }


            sort(temp.begin(), temp.end());
            for(int x : temp){
                ans.push_back(x);
            }
            
        }

        return ans;
    }
};
