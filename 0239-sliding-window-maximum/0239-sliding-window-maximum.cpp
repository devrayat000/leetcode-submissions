class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // Max heap storing pairs of {value, index}
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});

            // Once the window reaches size k, start recording results
            if (i >= k - 1) {
                // Clean up the top of the heap if it falls outside the window
                while (maxHeap.top().second <= i - k) {
                    maxHeap.pop();
                }
                // The top is now guaranteed to be within the current window
                result.push_back(maxHeap.top().first);
            }
        }

        return result;
    }
};
