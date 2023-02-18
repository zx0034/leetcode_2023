/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int preSum = 0;
        unordered_map<int,int> mem;
        int res = 0;
        mem[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i] == 0 ? -1 : 1;
            if (mem.count(preSum) == 0) {
                mem[preSum] = i;
            } else {
                res = max(res, i-mem[preSum]);
            }
        }
        return res;
    }
};
// @lc code=end

