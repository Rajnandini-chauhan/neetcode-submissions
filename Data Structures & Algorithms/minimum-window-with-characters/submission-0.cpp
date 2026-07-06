class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        vector<int> required(128, 0);

        for (char ch : t) {
            required[ch]++;
        }

        int left = 0;
        int matched = 0;
        int minLength = INT_MAX;
        int startIndex = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];

            if (required[currentChar] > 0) {
                matched++;
            }

            required[currentChar]--;

            while (matched == t.size()) {
                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    startIndex = left;
                }

                char leftChar = s[left];
                required[leftChar]++;

                if (required[leftChar] > 0) {
                    matched--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};