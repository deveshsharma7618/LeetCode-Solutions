class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = height[0];
        int total = 0;
        int i = 0;
        int j = height.size()-1;
        int rmax = height[j];
        while( i < j){
            if(height[i] < height[j]){
                if(height[i] < lmax){
                    total += lmax-height[i];
                }else{
                    lmax = height[i];
                }
                i++;
            }else{
                if(height[j] < rmax){
                    total += rmax-height[j];
                }else{
                    rmax = height[j];
                }
                j--;
            }
        }

        return total;
    }
};
