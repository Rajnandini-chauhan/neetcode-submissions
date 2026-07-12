class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long total_hours = 0;
            
            for (int pile : piles) {
                total_hours += (pile + mid - 1) / mid;
            }
            
            if (total_hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};