class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int h : nums)
        {
            minheap.push(h);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
 return minheap.top();       
    }
};
