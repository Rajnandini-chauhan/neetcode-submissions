class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> seen; 
         for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[arr[i]] = i;
        }
        return {}; 
    }
};