/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
public:
    vector<int> preSum;
    Solution(vector<int>& w) {
        int n = w.size();
        preSum.resize(n+1);
        preSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + w[i-1];
        }
    }
    
    int pickIndex() {
        int n = preSum.size();
        int target = rand() % preSum[n-1] + 1; // not plus w[0]

        return left_bound(preSum, target) - 1;
    }

    int left_bound(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

