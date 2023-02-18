/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if( n == 0) {
            return "";
        }
        // 动态规划
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int len = 1;
        int start = 0;
        for(int L = 2; L <= n; L++) {
            // std::cout<<">>>>>>>>L="<<L<<"<<<<<<<<<"<<std::endl;
            for(int i = 0; i < n; i++) {
                int j = i + L - 1;
                // 越界
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j-i < 3) {
                        dp[i][j] = j-i+1;
                    } else {
                        dp[i][j] = dp[i+1][j-1] > 0 ? dp[i+1][j-1]+2 : 0;
                    }
                }
                if (dp[i][j] > len) {
                    len = dp[i][j];
                    start = i;
                }
                // std::cout<<i<<" "<<j<<" "<<dp[i][j]<<std::endl;
            }
        }

        return s.substr(start,len);
    }
};
// @lc code=end

