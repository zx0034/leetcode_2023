/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> counts;
        int n = p.size();
        for(char c : p) {
            counts[c]++;
        }
        int l = 0, r = 0;
        vector<int> res;
        while(r < s.size()) {
            if (counts.count(s[r]) == 0) {
                if (l == r) {
                    l++;
                    r++;
                } else {
                    while(l != r) {
                        counts[s[l]]++;
                        l++;
                    }
                }
            } else {
                if (counts[s[r]] > 0) {
                    counts[s[r]]--;
                    r++;
                    if (r-l == n) {
                        res.push_back(l);
                        while(l != r) {
                        counts[s[l]]++;
                        if (s[l] == s[r]) {
                            l++;
                            break;
                        }
                        l++;
                    }
                    }
                } else {
                   while(l != r) {
                        counts[s[l]]++;
                        if (s[l] == s[r]) {
                            l++;
                            break;
                        }
                        l++;
                    }
                }
            }
        }
        if (r - l == n) {
            res.push_back(l);
        }
        return res;
    }
};
// @lc code=end

