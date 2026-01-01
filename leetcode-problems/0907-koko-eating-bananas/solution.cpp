class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int speed) {
    long long hours = 0;

    for (int p : piles) {
        hours += (p + speed - 1) / speed;  // ceil(p / speed)
        if (hours > h) return false;
    }
    return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int minSpeed = 1;
        int maxSpeed = piles.back();
        int k = -1;
        while(minSpeed <= maxSpeed){
            int midSpeed = minSpeed + (maxSpeed - minSpeed)/2;
            if(isPossible(piles,h,midSpeed)){
                k = midSpeed;
                maxSpeed = midSpeed-1;
            }else{
                minSpeed = midSpeed+1;
            }
        }
        return k;
    }
};
