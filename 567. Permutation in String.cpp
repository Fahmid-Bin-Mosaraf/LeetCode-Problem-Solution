// Sliding Window Technique

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int>s1Count(26,0), s2Count(26,0);
        for(char c : s1){
            s1Count[c-'a']++;
        }

        int x = s1.size();
        for(int i= 0; i<x; i++){
            s2Count[s2[i]-'a']++;
        }

        if(s1Count == s2Count){
            return true;
        }

        for(int i = x; i < s2.size(); i++) {
            s2Count[s2[i]-'a']++;
            s2Count[s2[i-x] - 'a']--;

            if(s1Count == s2Count){
                return true;
            }
        }
        return false;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
