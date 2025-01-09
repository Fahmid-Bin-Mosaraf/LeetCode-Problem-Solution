// Stack

class MinStack {
public:
    stack<int>Stack;   
    stack<int>minimum; 

    MinStack() {

    }

    void push(int val) {
        Stack.push(val);

        if(minimum.empty() || val <= minimum.top()){
            minimum.push(val);
        }
    }

    void pop() {
        if(!Stack.empty()){
            int x = Stack.top();
            Stack.pop();

            if(x == minimum.top()){
                minimum.pop();
            }
        }
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return minimum.top();
    }
};

// Time Complexity: O(1)
// Space Complexity: O(n)
