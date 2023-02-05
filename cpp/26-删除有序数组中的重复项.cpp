/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        while (r < n) {
            // 找不同
            while(r < n && nums[l] == nums[r]) {
                r++;
            }
            // 替换
            if (r < n) {
                nums[l+1] = nums[r];
                l++;
                r++;
            }
        }
        return l+1;
    }
};
// @lc code=end

