// DP

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n, 0);

        for(int i=n-2; i>=0; i--){
            int j = i+1;
            while(j<n && temperatures[j] <= temperatures[i]){
                if(ans[j] == 0){
                    j = n;
                    break;
                }
                j += ans[j];
            }
            if(j < n){
                ans[i] = j-i;
            }
        }
        return ans;
    }
};


// TIme Complexity: O(n)
// Space Complexity: O(1)