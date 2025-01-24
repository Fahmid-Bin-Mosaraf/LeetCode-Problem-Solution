// Date: 01/24/2025
// 802. Find Eventual Safe States
// C++ Solution
// Reverse Topological Sort

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>reverse(n);
        vector<int>node(n, 0);

        for(int i=0; i<n; i++){
            for(int x : graph[i]){
                reverse[x].push_back(i);
                node[i]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; ++i){
            if(node[i] == 0){
                q.push(i);
            }
        }

        vector<int>Sort;
        while(!q.empty()){
            int y = q.front();
            q.pop();
            Sort.push_back(y);

            for(int z : reverse[y]){
                node[z]--;
                if(node[z] == 0){
                    q.push(z);
                }
            }
        }
        sort(Sort.begin(), Sort.end());
        return Sort;
    }
};


// Time Complexity: O(V+E+VlogV)
// Space Complexity: O(V+E)