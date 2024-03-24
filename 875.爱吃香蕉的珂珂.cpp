/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9 + 1;

        while(l < r) {
            int mid = l + (r - l) / 2;
            long t = 0;
            for(int i = 0; i < piles.size(); i++) {
                t += (piles[i] + mid - 1) / mid;
            }
            if(t <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

