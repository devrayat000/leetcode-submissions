class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        auto max_it = max_element(
            counts.begin(),
            counts.end(),
            [](const auto& p1, const auto& p2) {
                return p1.second < p2.second;
            }
        );
        return max_it->first;
    }
};