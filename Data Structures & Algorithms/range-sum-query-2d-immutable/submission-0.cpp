class NumMatrix {
public:
    vector<vector<int>> grid;
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        grid.assign(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = matrix[i][j];
            }
        }
        prefix.assign(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = grid[i - 1][j - 1] 
                               + prefix[i - 1][j] 
                               + prefix[i][j - 1] 
                               - prefix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2 + 1][col2 + 1] 
                  - prefix[row1][col2 + 1]
                  - prefix[row2 + 1][col1]
                  + prefix[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */