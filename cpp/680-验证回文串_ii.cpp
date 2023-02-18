/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, h = s.size()-1;
        while(l < h) {
            if (s[l] == s[h]) {
                l++;
                h--;
            } else {
                return validPalindrome(s,l+1,h) || validPalindrome(s,l,h-1);
            }
        }
        return true;
    }
    bool validPalindrome(string s,int l, int h) {
        while(l < h) {
            if (s[l] == s[h]) {
                l++;
                h--;
            } else {
                return false;
            }
        }
        return true;
        
    }
};
// @lc code=end

