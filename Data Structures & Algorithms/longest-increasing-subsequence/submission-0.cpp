class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums,0,-1);
    }
    int dfs(vector<int> &nums,int i,int j)
    {
        if(i == nums.size()) return 0;
        int lis =  dfs(nums,i+1,j);
        if(j == -1 || nums[j] < nums[i])
        {
            lis = max(lis,1+dfs(nums,i+1,i));

        }
        return lis;
    }
};
