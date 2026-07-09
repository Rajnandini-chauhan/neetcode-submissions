class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> d;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int val2 = d.top();
                d.pop();
                int val1 = d.top();
                d.pop();
                if (tokens[i] == "+") {
                    d.push(val1 + val2);
                } else if (tokens[i] == "-") {
                    d.push(val1 - val2);
                } else if (tokens[i] == "*") {
                    d.push(val1 * val2);
                } else if (tokens[i] == "/") {
                    d.push(val1 / val2);
                }
            } else {
                d.push(stoi(tokens[i]));
            }
        }
        return d.top();
    }
};