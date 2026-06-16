class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(hepler(vector<int>(nums.begin()+1,nums.end())),
                   hepler(vector<int>(nums.begin(),nums.end()-1)));

        
    }
    int hepler(vector<int> nums)
    {
        if(nums.empty() ) return 0;
        if(nums.size() == 1) return nums[0];
        int rb1 = 0;
        int rb2 = 0;
        for(auto a : nums)
        {
            int temp = max(rb1+a,rb2);
            rb1 = rb2;
            rb2 = temp;

        }
        return rb2;
    }
};
