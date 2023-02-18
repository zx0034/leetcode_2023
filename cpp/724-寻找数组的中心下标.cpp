/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1,0);
        vector<int> right(n+1,0);
        for(int i = 0; i < n; i++) {
            left[i+1] = left[i] + nums[i];
            right[i+1] = right[i] + nums[n-i-1];
            std::cout<<i+1<<" "<<left[i+1]<<" "<<right[i+1]<<std::endl;
        }
        for(int i = 0; i < n; i++) {
            if(left[i] == right[n-1-i]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

