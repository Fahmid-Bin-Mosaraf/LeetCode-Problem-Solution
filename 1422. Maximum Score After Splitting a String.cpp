// Sliding Window

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int total = 0;
        int zero = 0;
        int ans = -1;

        for(char c : s){
            if(c == '0'){
                total++;
            }
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == '0'){
                zero++;
            }
            
            int ansZero = total - zero;
            int ansOne = (n-i-1) - ansZero;

            ans = max(ans, zero+ansOne);
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)