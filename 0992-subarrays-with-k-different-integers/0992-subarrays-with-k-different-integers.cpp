class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int i = 0, res = 0;

        for (int j = 0; j < nums.size(); j++) {
            m[nums[j]]++;

            while (m.size() > k) {
                m[nums[i]]--;
                if (m[nums[i]] == 0) {
                    m.erase(nums[i]);
                }
                i++;
            }

            res += (j - i + 1);
        }

        return res;
    }
};