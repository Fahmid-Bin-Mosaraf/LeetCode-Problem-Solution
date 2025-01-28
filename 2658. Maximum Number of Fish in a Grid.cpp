// Date: 01/28/2025
// 2658. Maximum Number of Fish in a Grid
// C++ Solution
// BFS


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>a(m, vector<bool>(n, 0));
        int maxFish = 0;

        vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        auto isValid = [&](int r, int c){
            return r >= 0 && r<m && c >= 0 && c<n && grid[r][c]>0 && !a[r][c];
        };
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && !a[i][j]){
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    a[i][j] = 1;
                    
                    int totalFish = 0;
                    
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        totalFish += grid[r][c];
                        
                        for(auto [dr, dc] : directions){
                            int nr = r + dr;
                            int nc = c + dc;
                            if(isValid(nr, nc)){
                                q.push({nr, nc});
                                a[nr][nc] = 1;
                            }
                        }
                    }
                    maxFish = max(maxFish, totalFish);
                }
            }
        }
        return maxFish;
    }
};


// Time Complexity: O(m*n)
// Space Complexity: O(m*n)