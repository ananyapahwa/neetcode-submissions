class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        while( i < n-1 && j < n){
            j = i+1;
            while(j < n && prices[j] > prices[i]){
                ans = max(ans, prices[j]-prices[i]);
                j++;
            }
            if(j < n && prices[j] <= prices[i]) i = j;
        }

        return ans;
    }
};
