// Date: 01/29/2025
// 684. Redundant Connection
// C++ Solution
// Set Union

class Solution {
public:
    vector<int>a;
    int ans(int x){
        while (a[x] != -1){
            x = a[x];
        }
        return x;
    }
    
    bool Union(int x, int y){
        int rootX = ans(x);
        int rootY = ans(y);
        if(rootX == rootY){
            return 0;
        }
        a[rootX] = rootY; 
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        a.resize(n+1, -1);
        
        for(auto& x : edges){
            if(!Union(x[0], x[1])){
                return x;
            }
        }
        return {};
    }
};


// Time Complexity: O(n)
// Sapce Complexity: O(n)