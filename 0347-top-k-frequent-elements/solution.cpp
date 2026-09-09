class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums){
            if( mp.find(x) != mp.end()){
                mp[x]++;
            }else{
                mp[x] = 1;
            }
        }

        priority_queue<pair<int,int>> pq;
        for(auto & [num, freq] : mp){
            pq.push({freq, num});
        }

        vector<int> ans;
        int i = 0;
        while( i < k){
            pair<int,int> x = pq.top();
            pq.pop();
            ans.push_back(x.second);
            i++;
        }

        return ans;

    }
};
