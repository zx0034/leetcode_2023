/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> counts;
        int n = s1.size();
        for(char c : s1) {
            counts[c]++;
        }
        int l = 0, r = 0;
        while(r < s2.size()) {
            if (counts.count(s2[r]) == 0) {
                if (l == r) {
                    l++;
                    r++;
                } else {
                    while(l != r) {
                        counts[s2[l]]++;
                        l++;
                    }
                }
            } else {
                if (counts[s2[r]] > 0) {
                    counts[s2[r]]--;
                    r++;
                    if (r-l == n) {
                        return true;
                    }
                } else {
                   while(l != r) {
                        counts[s2[l]]++;
                        if (s2[l] == s2[r]) {
                            l++;
                            break;
                        }
                        l++;
                    }
                }
            }
        }
        if (r - l == n) {
            return true;
        }
        return false;
    }
};
// @lc code=end

