/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 1;
        for(int weight : weights) {
            left = max(weight,left);
            right += weight;
        }
        while(left < right) {
            int mid = left + (right - left) / 2;

            int time = 0;
            for(int i = 0; i < weights.size(); ) {
                int cap = mid;
                while(i < weights.size()) {
                    if(cap < weights[i]) break;
                    else cap -= weights[i];
                    i++;
                }
                time++;
            }

            if(time <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

