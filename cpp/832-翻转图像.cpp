/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        auto swap = [](int &a, int& b) {
            int tmp = a;
            a = b;
            b = tmp;
            return ; 
        };
        for(int i = 0; i < image.size(); i++) {
            int l = 0, r = image[0].size()-1;
            while(l < r) {
                swap(image[i][l++],image[i][r--]);
            }
        }
        for(int i = 0; i < image.size(); i++) {
            for(int j = 0; j < image[0].size(); j++) {
                image[i][j] = 1 - image[i][j];
            }
        }
        return image;
    }
};
// @lc code=end

