class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left =0;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[left] > prices[i]) {
                left = i;
            }
            int diff = prices[i] - prices[left];
            if (diff > result) {
                result = diff;
            }

        }
        return result;
        
    }
};
