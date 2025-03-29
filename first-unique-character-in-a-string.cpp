class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Find the first character that appears exactly once
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character is found, return -1
        return -1;
        
    }
};
