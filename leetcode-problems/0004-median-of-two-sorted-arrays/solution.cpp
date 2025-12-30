class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        int i=0, j = 0;
        while( i < m && j < n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i++]);
            }else{
                ans.push_back(nums2[j++]);
            }
        }

        while(i < m)
            ans.push_back(nums1[i++]);

        while(j < n)
            ans.push_back(nums2[j++]);

        if((m + n)%2 == 0){
            int mid = (m+n)/2-1;
            return (ans[mid]+ans[mid+1])/2.0;
        }else{
            return ans[(m+n)/2.0];
        }
        
    }
};
