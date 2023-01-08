/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        for(int i = n-1; i >= 0; i--) {
            int tmp = digits[i] + c;
            c = tmp / 10;
            digits[i] = tmp % 10;
        }
        if (c != 0) {
            digits.insert(digits.begin(),c);
        }
        return digits;
    }
};
// @lc code=end

