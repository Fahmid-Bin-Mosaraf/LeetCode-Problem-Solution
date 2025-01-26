// Date: 01/26/2025
// 2127. Maximum Employees to Be Invited to a Meeting
// C++ Solution
// Topological Sorting and Cycle Detection.

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int longCycle = 0;
        int twoCycle = 0;
        vector<int> degree(n, 0);
        vector<int> depth(n, 1);

        for(int i=0; i<n; i++){
            degree[favorite[i]]++;
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int y = favorite[x];
            depth[y] = max(depth[y], depth[x] + 1);
            if(--degree[y] == 0){
                q.push(y);
            }
        }

        for(int i=0; i<n; i++){
            if(degree[i] == 0){
                continue;
            }
            int len = 0;
            int x = i;
            while(degree[x] != 0){
                degree[x] = 0;
                len++;
                x = favorite[x];
            }
            if(len == 2){
                twoCycle += depth[i] + depth[favorite[i]];
            } 
            else{
                longCycle = max(longCycle, len);
            }
        }
        return max(longCycle, twoCycle);
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)