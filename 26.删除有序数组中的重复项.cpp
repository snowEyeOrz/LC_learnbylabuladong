/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int base=0,search=0;
        while(++search<nums.size()){
            if(nums[base]!=nums[search]){
                base++;
                nums[base]=nums[search];
            }
        }
        return ++base;
    }
};
// @lc code=end

