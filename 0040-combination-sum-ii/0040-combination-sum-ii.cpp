class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        
        // Start at index 0, with prevPicked = false
        solve(candidates, target, 0, false, comb, ans);
        return ans;
    }

private:
    void solve(vector<int>& candidates, int target, int idx, bool prevPicked,
               vector<int>& comb, vector<vector<int>>& ans) {
        // Base case: valid combination found
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        
        // Base case: out of bounds or current number is too large (since sorted)
        if (idx == candidates.size() || candidates[idx] > target) {
            return;
        }

        // BRANCH 1: SKIP candidates[idx]
        // We set prevPicked = false because we deliberately skipped this element
        solve(candidates, target, idx + 1, false, comb, ans);

        // BRANCH 2: PICK candidates[idx]
        // Duplicate check: If this number is the same as the previous one, 
        // we can ONLY pick it if we ALSO picked the previous one.
        if (idx > 0 && candidates[idx] == candidates[idx - 1] && !prevPicked) {
            return;
        }

        comb.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx + 1, true, comb, ans);
        comb.pop_back(); // Backtrack
    }
};