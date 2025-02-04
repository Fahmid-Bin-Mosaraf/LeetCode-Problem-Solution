// Date: 02/04/2025
// 1800. Maximum Ascending Subarray Sum
// C++ Solution

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int ans = nums[0];

        for(int i=1; i< nums.size(); i++) {
            if(nums[i] > nums[i-1]){
                sum += nums[i]; 
            } 
            else{
                sum = nums[i]; 
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)
