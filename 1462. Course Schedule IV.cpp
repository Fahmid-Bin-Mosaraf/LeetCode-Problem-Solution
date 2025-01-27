// Date: 01/27/2025
// 462. Course Schedule IV
// C++ Solution
// BFS

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>a(numCourses);
        for(const auto& x : prerequisites){
            a[x[0]].push_back(x[1]);
        }

        vector<unordered_set<int>>b(numCourses);
        for(int i=0; i<numCourses; i++){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int next : a[curr]){
                    if(!b[i].count(next)){
                        b[i].insert(next);
                        q.push(next);
                    }
                }
            }
        }

        vector<bool>ans;
        for(const auto& y : queries){
            ans.push_back(b[y[0]].count(y[1]) > 0);
        }
        return ans;
    }
};


// Time Complexity: O(V*E+Q)
// Space Complexity: O(V^2+E)

