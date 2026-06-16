class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char t :tasks )
        {
            count[t - 'A']++;
        }
        int maxf = *max_element(count.begin(),count.end());
        int maxc = 0;
        for(int i : count)
        {
            if ( i == maxf)
        {
            maxc++;
        }
        }

int time = (maxf - 1)*(n +1)+maxc;
return max((int)tasks.size(),time);        
    }
};
