/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < nums.size(); i++) {
            valToIndex[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int goal = target - nums[i];
            if (valToIndex.count(goal)) {
                if (valToIndex[goal] == i) continue; // 去重
                return vector<int>{i,valToIndex[goal]};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

