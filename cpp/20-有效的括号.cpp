/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    unordered_map<char,char> right = {{')','('},{']','['},{'}','{'}};
    unordered_set<char> left = {'(','{','['};
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if (left.count(s[i]) > 0) {
                st.push(s[i]);
            } else {
                if (st.size() == 0) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (top != right[s[i]]) {
                    return false;
                }
            }
        }
        if (st.size() != 0) {
            return false;
        }
        return true;
    }
};
// @lc code=end

