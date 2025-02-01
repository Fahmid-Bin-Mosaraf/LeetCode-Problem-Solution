// Date: 01/02/2025
// 3151. Special Array I
// C++ Solution

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i=1; i<n; i++){
            if((nums[i]%2) == (nums[i-1] % 2)){
                return false;
            }
        }
        return true;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)