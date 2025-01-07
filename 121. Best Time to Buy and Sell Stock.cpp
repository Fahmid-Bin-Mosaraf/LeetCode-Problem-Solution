// Two Pointers Technique
// Brute Force Method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int ans = 0;
        while(j < prices.size()){
            if(prices[i] < prices[j]){
                int profit = prices[j] - prices[i];
                ans = max(ans, profit);
            } 
            else{
                i = j;
            }
            j++;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
