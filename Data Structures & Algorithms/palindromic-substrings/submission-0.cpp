class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            count += expandFromCenter(s, i, i);
            count += expandFromCenter(s, i, i + 1);
        }
        
        return count;
    }


    int expandFromCenter(const string& s, int left, int right) {
        int palindromes = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            palindromes++;
            left--;
            right++;
        }
        
        return palindromes;
    }
};