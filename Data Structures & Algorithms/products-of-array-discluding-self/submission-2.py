class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        perfix = 1 
        for s in range(len(nums)):
            res[s] = perfix 
            perfix  *= nums[s]
        postfix = 1 
        for s in range(len(nums) -1 ,-1,-1):
            res[s] *= postfix
            postfix *= nums[s]
        return res