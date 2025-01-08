// Sliding Window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int ans = 0;
        int j = 0;
        int maximum = 0;

        for(int i=0; i<s.size(); i++){
            count[s[i] - 'A']++;
            maximum = max(maximum, count[s[i] - 'A']);

            while((i-j+1) - maximum > k){
                count[s[j] - 'A']--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
