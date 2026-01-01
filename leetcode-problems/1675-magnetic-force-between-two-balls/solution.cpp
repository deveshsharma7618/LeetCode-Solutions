class Solution {
public:
    bool isPossible(vector<int> &stalls, int k, int maxDist){
        int x = 1;
        int y = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i] - y >= maxDist){
                x++;
                y = stalls[i];
            }
            
            if(x >= k){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int minDist = 1;
        int ans = -1;
        int maxDist = stalls[stalls.size()-1]-stalls[0];
        while(minDist <= maxDist){
            int midDist = minDist + (maxDist-minDist)/2;
            if(isPossible(stalls,k,midDist)){
                ans = midDist;
                minDist = midDist+1;
            }else{
                maxDist = midDist-1;
            }
        }
        return ans;
    }
};
