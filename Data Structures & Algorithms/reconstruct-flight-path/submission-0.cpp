class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> result;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // Build graph
        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }

        // Sort adjacency lists in reverse order
        for (auto& [key, vec] : adj) {
            sort(vec.rbegin(), vec.rend());
        }

        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(string src) {
        auto& destinations = adj[src];

        while (!destinations.empty()) {
            string next = destinations.back();
            destinations.pop_back();
            dfs(next);
        }

        result.push_back(src);
    }
};
