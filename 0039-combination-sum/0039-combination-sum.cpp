class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        makeCombination(candidates, target, 0, ans, comb);
        return ans;
    }

private:
    void makeCombination(vector<int>& candidates, int target, int idx,
                         vector<vector<int>>& ans, vector<int>& comb) {
        if (idx == candidates.size() || target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back({comb});
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(candidates, target - candidates[idx], idx, ans, comb);

        comb.pop_back();
        makeCombination(candidates, target, idx + 1, ans, comb);
    }
};