class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int m = arr1.size();
        int n = arr2.size();

        int len = 0;

        for (int i = 0; i < n; i++) {
            int x = arr2[i];

            for (int j = len; j < m; j++) {
                if(arr1[j] == x){
                    swap(arr1[len], arr1[j]);
                    len++;
                }
            }
        }

        sort(arr1.begin() + len, arr1.end());
        return arr1;

    }
};