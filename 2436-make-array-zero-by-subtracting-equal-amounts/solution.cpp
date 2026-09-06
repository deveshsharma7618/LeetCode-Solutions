class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> set;
        int ans = 0;
        int maxNum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }

        for (int x : set) {
            if (x != 0) {
                minHeap.push(x);
            }

            if (x > maxNum) {
                maxNum = x;
            }
        }

        int i = 0;
        while (maxNum > 0) {
            int x = minHeap.top() - i;
            minHeap.pop();
            if (x < maxNum) {
                maxNum -= x;
            } else {
                maxNum = 0;
            }
            i += x;
            ans++;
        }

        return ans;
    }
};
