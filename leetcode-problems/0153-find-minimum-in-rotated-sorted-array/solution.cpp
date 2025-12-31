class Solution {
public:
    int findMin(vector<int>& arr) {
        int end = arr.size()-1;
        int start = 0;
        int ans = arr[0];
        while(start <= end){
            int mid = start + (end - start)/2;

            // left sorted
            if(arr[mid] >= arr[start]){
                ans = ans > arr[start] ? arr[start] : ans;
            start = mid+1;
            }else{
                ans = ans > arr[mid] ? arr[mid] : ans;
                end = mid-1;
            }
        }
        return ans;
    }
};
