class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k = 1;
        vector<int> row(n,0);
        vector<vector<int>> ans(n,row);
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        while(top <= bottom && left <= right){
            for(int i=left;i <= right; i++){
                ans[top][i] = k;
                k++;
            }
            top++;

            for(int i=top;i <= bottom; i++){
                ans[i][right] = k;
                k++;
            }
            right--;


            for(int i=right;i >= left; i--){
                ans[bottom][i] = k;
                k++;
            }
            bottom--;

            for(int i=bottom;i >= top; i--){
                ans[i][left] = k;
                k++;
            }
            left++;

        }
        return ans;
    }
};
