class NumMatrix {
private:
    vector<int> sums;
    int m, n;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        sums.reserve(m * n + 1);
        sums[0] = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                sums[r * n + c + 1] = sums[r * n + c] + matrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int i = row1; i <= row2; i++) {
            sum += sums[i * n + col2 + 1] - sums[i * n + col1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */