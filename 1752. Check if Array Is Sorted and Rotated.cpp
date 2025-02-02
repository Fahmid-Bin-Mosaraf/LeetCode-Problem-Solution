// Date: 02/02/2025
// 1752. Check if Array Is Sorted and Rotated
// C++ Solution
// Counting decreasing point of the array

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }

        if(nums[n-1] > nums[0]){
            count++;
        }
        return count <= 1;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)