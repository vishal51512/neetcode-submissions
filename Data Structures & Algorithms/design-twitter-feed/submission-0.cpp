class Twitter {
private:
    int time;
    
    // user -> set of followees
    unordered_map<int, unordered_set<int>> followmap;
    
    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweetmap;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        // Add user's own tweets
        for (auto &t : tweetmap[userId])
            pq.push(t);

        // Add followees' tweets
        for (int f : followmap[userId]) {
            for (auto &t : tweetmap[f])
                pq.push(t);
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
