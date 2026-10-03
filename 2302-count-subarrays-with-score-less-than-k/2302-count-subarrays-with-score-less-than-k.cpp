class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long k) {
        int n = arr.size();
        int start = 0;
        long long sum = 0;
        long long count = 0;

        for (int end = 0; end < n; end++) {
            sum += arr[end];

            while (sum * ( end - start + 1) >= k) {
                sum -= arr[start];
                start++;
            }

            count += (end - start + 1);
        }

        return count;
    }
};