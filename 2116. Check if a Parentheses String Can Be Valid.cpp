// Greedy algorithm

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2 != 0){
            return false;
        }

        int minimum = 0;
        int maximum = 0;

        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                maximum++;    
                minimum--; 
            } 
            else if(s[i] == '('){
                maximum++;
                minimum++;
            } 
            else{
                maximum--;
                minimum--;
            }

            if (maximum < 0){
                return false;
            }
            minimum = max(minimum, 0); 
        }

        minimum = 0;
        maximum = 0;

        for(int i=n-1; i>=0; i--){
            if(locked[i] == '0'){
                maximum++;    
                minimum--;   
            } 
            else if(s[i] == ')'){
                maximum++;
                minimum++;
            }
            else{ 
                maximum--;
                minimum--;
            }

            if(maximum < 0){
                return false;
            }
            minimum = max(minimum, 0); 
        }
        return true;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)