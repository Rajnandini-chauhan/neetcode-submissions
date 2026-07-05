class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int max_len = 0;
        map<char, int> h;
        
        for (high = 0; high < s.size(); high++) {
            h[s[high]]++; 
            
          
            while (h[s[high]] > 1) {
                h[s[low]]--;
                low++;       
            }
            
          
            max_len = max(max_len, high - low + 1);
        }
        
        return max_len;
    }
};