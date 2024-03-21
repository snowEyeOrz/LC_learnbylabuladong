/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int base=0,search=0;
        while(search<nums.size()){
            if(nums[search]!=val){
                nums[base]=nums[search];
                base++;
            }
            search++;
        }
        return base;
    }
};
// @lc code=end

