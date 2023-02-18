/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(char c : s) {
            if (c < '0' || c > 'z' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a')) {
                continue;
            }
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
            tmp.push_back(c);
        }
        // std::cout<<tmp<<std::endl;
        // 边界case
        if(tmp.size() == 0) {
            return true;
        }
        int l = 0, r = tmp.size()-1;
        while(l < r) {
            if (tmp[l] != tmp[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end

