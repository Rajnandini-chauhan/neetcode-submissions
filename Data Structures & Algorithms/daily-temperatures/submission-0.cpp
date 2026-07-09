class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); // Initialize result array with 0s
        stack<int> st;         // Stack to store indices of the days
        
        for (int i = 0; i < n; i++) {
            // While stack is not empty and the current day's temperature 
            // is warmer than the temperature at the index on top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_index = st.top();
                st.pop();
                
                // Calculate how many days passed between the previous day and today
                res[prev_index] = i - prev_index;
            }
            
            // Push current day's index onto the stack
            st.push(i);
        }
        
        return res;
    }
};
