class Solution {
public:
int can(vector<int>& piles,int h, int k)
{
    long long hour = 0;
    for( int pile:piles)
    {
        hour += pile/k;
        if(pile % k != 0) hour++;
        if(hour > h) return false;
    }
    return hour <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r;
        while( l<= r)
   {
     int m = l +(r-l)/2;
     if(can(piles,h,m))
     {
        res = m;
        r = m-1;
     }
     else
     {
        l = m+1;
     }
   }
   return res;
    }
};
