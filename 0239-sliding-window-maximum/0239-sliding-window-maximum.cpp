class Solution {
private:
    vector<int> maxSlidingWindowDeque(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n - k + 1);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ret[i-k+1] = nums[dq.front()];
            }
        }
        return ret;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> result;
        // // Max heap storing pairs of {value, index}
        // priority_queue<pair<int, int>> maxHeap;

        // for (int i = 0; i < nums.size(); ++i) {
        //     maxHeap.push({nums[i], i});

        //     // Once the window reaches size k, start recording results
        //     if (i >= k - 1) {
        //         // Clean up the top of the heap if it falls outside the window
        //         while (maxHeap.top().second <= i - k) {
        //             maxHeap.pop();
        //         }
        //         // The top is now guaranteed to be within the current window
        //         result.push_back(maxHeap.top().first);
        //     }
        // }

        // return result;
        return maxSlidingWindowDeque(nums, k);
    }
};
