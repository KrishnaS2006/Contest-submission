class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // stores number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                // If the complement exists in the map, return the indices
                return {map[complement], i};
            }
            map[nums[i]] = i;  // Otherwise, store the current number and its index
        }
        return {};  // return an empty vector if no solution is found
    }
};
