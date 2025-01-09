// Stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                Stack.push(c);
            } 
            else{
                if (Stack.empty()){
                    return false;
                }

                char top = Stack.top();
                Stack.pop();

                if((c == ')' && top != '(') || (c == '}' && top != '{') ||
                    (c == ']' && top != '[')){
                    return false;
                }
            }
        }
        return Stack.empty();
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)