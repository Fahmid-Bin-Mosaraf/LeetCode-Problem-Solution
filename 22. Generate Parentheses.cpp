// DP
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>>ans(n+1);
        ans[0] = {""};

        for(int i=0; i<=n; i++){
            for(int j=0; j<i; j++){
                for(const string& l : ans[j]){
                    for (const string& r : ans[i-j-1]) {
                        ans[i].push_back("(" + l + ")" + r);
                    }
                }
            }
        }
        return ans[n];
    }
};


// Time Complexity: O(n^2)
// Space Complexity: O(n^3)