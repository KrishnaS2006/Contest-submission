class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        
        // Step 1: Count the frequency of each element in the nums array
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Create a min-heap based on frequency (priority queue)
        // The pair is {frequency, number}, and we want the heap to be ordered by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Step 3: Build the heap with the frequency of each element
        for (auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            // If the heap exceeds size k, pop the smallest frequency element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 4: Extract the elements from the heap and store them in the result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        // Step 5: Reverse the result vector since we need the most frequent elements first
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
