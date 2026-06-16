class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l =0 ;
        int r =1;
        int pro = 0;
        while(r  < prices.size())
        {
            if(prices[l] < prices[r])
            {
                int profit  = prices[r] - prices[l];
                pro = max(pro,profit);
            }
            else
            {
                l =r;
            }
            r++;
        }
        return pro;
    }
};
