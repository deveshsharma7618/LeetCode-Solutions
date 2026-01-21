class Solution {
public:
    bool isPossible(vector<int> &b,int t,int k, int m){
        int x = 0;
        for(int i=0;i<b.size();i++){
            if(b[i] <= t){{
                x++;
            }
            if(x == k){
                m--;
                x = 0;
            }
            if(!m){
                return true;
            }}else{
                x = 0;
            }
        }
        return !m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k)
            return -1;
        int start = bloomDay[0];
        int end = bloomDay[0];
        for(int i=0;i<bloomDay.size();i++){
            end = max(bloomDay[i], end);
            start = min(bloomDay[i],start);
        }
        int mid;
        int ans = -1;
        while(start <= end){
            mid = start + (end-start)/2;
            if(isPossible(bloomDay,mid,k,m)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
