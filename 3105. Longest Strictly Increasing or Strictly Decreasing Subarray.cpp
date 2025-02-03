// Date: 02/03/2025;
// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// C++ Solution
// Sliding Window


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 1;
        }
        
        int ans = 1;
        int x = 1; 
        int y = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                x++;
                y = 1;
            } 
            else if(nums[i] < nums[i-1]){
                y++;
                x = 1;
            } 
            else{
                x = 1;
                y = 1;
            }
            ans = max(ans, max(x, y));
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)