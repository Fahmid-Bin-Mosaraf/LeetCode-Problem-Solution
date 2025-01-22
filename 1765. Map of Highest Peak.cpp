// Date: 01/22/2025
// 1765. Map of Highest Peak 
// C++ Solution
// Breadth-First Search (BFS)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, INT_MAX));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0; 
                } 
                else{
                    if(i > 0 && height[i-1][j] != INT_MAX){
                        height[i][j] = min(height[i][j], height[i-1][j] + 1);
                    }
                    if(j > 0 && height[i][j-1] != INT_MAX){
                        height[i][j] = min(height[i][j], height[i][j-1] + 1);
                    }
                }
            }
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i < m - 1 && height[i+1][j] != INT_MAX){
                    height[i][j] = min(height[i][j], height[i+1][j] + 1);
                }
                if(j < n - 1 && height[i][j+1] != INT_MAX){
                    height[i][j] = min(height[i][j], height[i][j+1] + 1);
                }
            }
        }
        return height;
    }
};


// Time and Space Complexity: O(m*n)