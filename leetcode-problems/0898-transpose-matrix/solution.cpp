class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose;
        for(int j = 0; j < matrix[0].size() ; j++){
            vector<int> temp;
            for(int i = 0; i < matrix.size(); i++){
                temp.push_back(matrix[i][j]);
            }
            transpose.push_back(temp);
        }
        return transpose;
    }
};
