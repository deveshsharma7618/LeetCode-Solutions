class Solution {
public:
    void make_zero(vector<vector<int>> &mat, int i, int j){
        for(int k = 0;k<mat[0].size();k++){
            mat[i][k] = 0;
        }
        for(int k = 0;k<mat.size();k++){
            mat[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroIdx;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    zeroIdx.push_back({i,j});
                }
            }
        }

        for(int i=0;i<zeroIdx.size();i++){
            make_zero(matrix,zeroIdx[i].first,zeroIdx[i].second);
        }
        
    }
};
