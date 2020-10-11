//122. 买卖股票的最佳时机 II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int protile = 0;

        for(int i = 0; i + 1< prices.size();i++){
            protile += max(prices[i+1] - prices[i],0);
        }
        return protile;
    }
};