class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            int height = min(heights[left], heights[right]);
            int width = right-left;
            ans = max(ans, height*width);

            if(heights[left] < heights[right]){
                left++;
            } 
            else{
                right--;
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Spcae Complexity: O(1)