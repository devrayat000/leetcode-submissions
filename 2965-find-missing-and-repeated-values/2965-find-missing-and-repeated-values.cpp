class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> line(n*n+1, 0);
        for (auto col : grid) {
            for (auto num : col) {
                line[num]++;
            }
        }

        int a = 0, b = 0;
        for (int i = 1; i < line.size(); i++) {
            if (line[i] == 2) {
                a = i;
            }
            if (line[i] == 0) {
                b = i;
            }
        }
        return {a, b};
    }
};