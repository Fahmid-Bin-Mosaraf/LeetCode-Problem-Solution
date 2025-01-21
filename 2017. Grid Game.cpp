// Prefix Sum

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top(n + 1, 0);
        vector<long long> bot(n + 1, 0);

        for(int i=0; i<n; i++){
            top[i+1] = top[i] + grid[0][i];
            bot[i+1] = bot[i] + grid[1][i];
        }

        long long ans = LLONG_MAX;
        for (int i=0; i<n; i++){
            long long scoreTop = top[n] - top[i+1]; 
            long long scoreBot = bot[i];          
            long long maximum = max(scoreTop, scoreBot);
            ans = min(ans, maximum);
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)