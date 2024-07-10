class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(char c : s){
            if(isalnum(c)){
                s2 += tolower(c);
            }
        }
        
        int len = s2.length();
        for(int i=0; i<len/2; i++){
            if(s2[i] != s2[len - i- 1]){
                return false;
            }
        }
        return true;
    }
};

// Time complexity : O(n)
// Space complesity : O(n)