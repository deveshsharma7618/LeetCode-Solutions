class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        vector<int> profit(n,0);

        for(int i=1;i<n;i++){
            int currProfit = prices[i] - prices[i-1];
            int prevMaxProfit = 0;
            for(int j=i-1;j>=0;j--){
                if(prevMaxProfit < profit[j]){
                    prevMaxProfit = profit[j];
                }
            }
            if(currProfit > profit[i]){
                profit[i] = currProfit + prevMaxProfit;
            }
        }

        int max_profit = 0;
        for(int i=0;i<n;i++){
            if(profit[i] > max_profit){
                max_profit = profit[i];
            }
        }
        return max_profit;
    }
};
