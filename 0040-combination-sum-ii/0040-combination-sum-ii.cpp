class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;

        makeCombination(candidates, target, 0, ans, comb);
        return ans;
    }

private:
    void makeCombination(vector<int>& candidates, int target, int idx,
                         vector<vector<int>>& ans, vector<int>& comb) {

        if (target == 0) {
            ans.push_back({comb});
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);
            makeCombination(candidates, target - candidates[i], i + 1, ans,
                            comb);

            comb.pop_back();
        }
    }
};