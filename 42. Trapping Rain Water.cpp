// Two Pointers Technique
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int left = 0;
        int right = height.size()-1;

        int leftMax = height[left]; 
        int rightMax = height[right];

        int ans = 0;

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
            } 
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)