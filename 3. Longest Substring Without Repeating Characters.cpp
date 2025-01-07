// Sliding Window(Optimal Solution)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int len = 0;
        int ans = 0;

        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                ans = max(ans, mp[s[i]]+1);
            }
            mp[s[i]] = i;
            len = max(len, i-ans+1);
        }
        return len;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(m)
