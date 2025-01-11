// palindrome

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k){
            return false;
        }

        vector<int>lower(26, 0);
        int Oddcount = 0;

        for(char c : s){
            lower[c - 'a']++;
        }

        for(int count : lower){
            if(count%2 != 0){
                Oddcount++;
            }
        }
        return Oddcount <= k;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)