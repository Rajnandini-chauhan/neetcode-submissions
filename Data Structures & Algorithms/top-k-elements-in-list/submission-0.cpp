class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
        unordered_map<int, int> frequencyMap;
        
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (const auto& pair : frequencyMap) {
            int element = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(element);
        }
        
        vector<int> result;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result; 

    }
};
