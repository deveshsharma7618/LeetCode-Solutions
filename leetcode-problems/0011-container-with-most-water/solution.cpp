class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        int h = height[0];
        while(i < j){
            h = min(height[i], height[j]);
            ans = max(ans, (j-i)*h);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }

};
