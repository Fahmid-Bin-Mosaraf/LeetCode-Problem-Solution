class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;

        for (int i : nums) {
            if (i != 0) {
                nums[zero++] = i;
            }
        }
        while (zero < nums.size()) {
            nums[zero++] = 0;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)