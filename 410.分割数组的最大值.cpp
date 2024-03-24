/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 1;
        for(int num : nums) {
            left = max(num,left);
            right += num;
        }
        while(left < right) {
            int mid = left + (right - left) / 2;

            int time = 0;
            for(int i = 0; i < nums.size(); ) {
                int cap = mid;
                while(i < nums.size()) {
                    if(cap < nums[i]) break;
                    else cap -= nums[i];
                    i++;
                }
                time++;
            }

            if(time <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

