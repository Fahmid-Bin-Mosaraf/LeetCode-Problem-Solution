// Date: 01/30/2025
// 2493. Divide Nodes Into the Maximum Number of Groups
// C+ Solution
// Graph Traversal


class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>a(n+1, 0);
        vector<int>b;
        int ans = 0;

        function<bool(int, int)>fun = [&](int node, int c){
            a[node] = c;
            b.push_back(node);
            for(int i : adj[node]){
                if(a[i] == 0){
                    if(!fun(i, 3-c)){
                        return 0;
                    }
                } 
                else if (a[i] == c){
                    return 0;
                }
            }
            return 1;
        };

        function<int(int)>bfs = [&](int start){
            queue<int>q;
            unordered_map<int, int>depth;
            q.push(start);
            depth[start] = 1;
            int maximum = 1;

            while(!q.empty()){
                int node = q.front(); q.pop();
                for(int i : adj[node]){
                    if(!depth.count(i)){
                        depth[i] = depth[node] + 1;
                        maximum = max(maximum, depth[i]);
                        q.push(i);
                    }
                }
            }
            return maximum;
        };

        for(int i=1; i<=n; i++){
            if(a[i] == 0){
                b.clear();
                if(!fun(i, 1)){
                    return -1;
                }

                int len = 0;
                for(int node : b){
                    len = max(len, bfs(node));
                }
                ans += len;
            }
        }
        return ans;
    }
};


// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
