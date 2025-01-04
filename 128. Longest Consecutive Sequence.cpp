class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(), nums.end());

        int ans = 1;
        int seq = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1]+1){
                    seq++;
                }
                else{
                    ans = max(ans, seq);
                    seq = 1;
                }
            }
        }
        return max(ans, seq);
    }
};


// Time Complexity: O(nlogn)
// Space Complexity: O(n)