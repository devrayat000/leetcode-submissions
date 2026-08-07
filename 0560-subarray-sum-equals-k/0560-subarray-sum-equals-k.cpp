class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 1. Only use the map to track running frequencies
        unordered_map<int, int> freq;
        freq[0] =
            1; // Base case: A prefix sum of 0 has occurred 1 time initially

        int count = 0;
        int current_prefix = 0; // Tracks running prefix sum on the fly

        // 2. Process everything in a single, high-efficiency pass
        for (int num : nums) {
            current_prefix += num;
            int req = current_prefix - k;

            // Check if the required complement prefix sum exists
            if (freq.contains(req)) { // .contains() requires C++20
                count += freq[req];
            }

            // Record the current running prefix sum
            freq[current_prefix]++;
        }

        return count;
    }
};