/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        sum = vector<vector<int>>(m,vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i ==0 && j == 0) {
                    sum[i][j] = matrix[i][j];
                } else if (i == 0) {
                    sum[i][j] = sum[i][j-1] + matrix[i][j];
                } else if (j == 0) {
                    sum[i][j] = sum[i-1][j] + matrix[i][j]; 
                } else {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
                }
                // std::cout <<i<<" "<<j<<" "<<sum[i][j] << std::endl;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2][col2];
        if (row1 > 0) {
            res -= sum[row1-1][col2]; 
        }
        if (col1 > 0) {
            res -= sum[row2][col1-1];
        }
        if (row1 > 0 && col1 > 0) {
            res += sum[row1-1][col1-1];
        }
        return res;
    }
private:
    vector<vector<int>> sum;
    int m,n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

