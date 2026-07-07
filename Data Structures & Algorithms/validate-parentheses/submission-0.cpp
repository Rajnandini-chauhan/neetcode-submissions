class Solution {
public:
    bool isValid(string s) {
        stack<char> d;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                d.push(c);
            } 
            else {
                if (d.empty()) return false;
                if ((c == ')' && d.top() != '(') ||
                    (c == '}' && d.top() != '{') ||
                    (c == ']' && d.top() != '[')) {
                    return false; 
                }
                d.pop();
            }
        }
        return d.empty();
    }
};
