class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = nums[0] , cursum = 0;
        for(int num : nums)
        {
            if(cursum < 0)
            {
                cursum = 0;
            }
            cursum += num;
            maxsub = max(cursum,maxsub);
        }
return maxsub;
    }
};
