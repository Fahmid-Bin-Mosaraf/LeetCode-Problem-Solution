// Date: 06/02/2025
// 1726. Tuple with Same Product
// C++ Solution
// Hash Map

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int>count;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                int x = nums[i]*nums[j];
                ans += count[x]*8; 
                count[x]++;
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)