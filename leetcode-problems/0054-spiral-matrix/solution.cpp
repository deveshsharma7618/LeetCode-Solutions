class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // left → right
            for (int col = left; col <= right; col++)
                ans.push_back(matrix[top][col]);
            top++;

            // top → bottom
            for (int row = top; row <= bottom; row++)
                ans.push_back(matrix[row][right]);
            right--;

            // right → left
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    ans.push_back(matrix[bottom][col]);
                bottom--;
            }

            // bottom → top
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    ans.push_back(matrix[row][left]);
                left++;
            }
        }

        return ans;
    }
};

