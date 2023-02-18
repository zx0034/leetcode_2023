// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        int res = n == 0 ? 0 : 1;
        unordered_map<char,int> mem;
        while(r < n) {
            char c = s[r];
            mem[c]++;
            if (mem[c] == 1) {
                res = max(res,r-l+1);
            }
            while(mem[c] > 1 && l < r) {
                res = max(res, r-l);
                char d = s[l];
                mem[d]--;
                l++;
            }
            r++;
        }
        return res;
    }
};
// @lc code=end

