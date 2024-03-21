/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }
//target int->long是为了防止溢出
    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long target) {
        vector<vector<int>> res;
        if(n < 2){ 
            return {};
        }
        if(n > nums.size()){ 
            return {};
        }

        if(n == 2){
            int left = start;
            int right = nums.size()-1;

            while(left < right){
                int loVal = nums[left];
                int hiVal = nums[right];
                int sum = loVal + hiVal;
                if (target == sum){
                    res.push_back({loVal, hiVal});
                    while (left < right && nums[left] == loVal) left++;
                    while (left < right && nums[right] == hiVal) right--;                 
                }else if(target < sum){
                    while (left < right && nums[right] == hiVal) right--;                  
                }else{
                    while (left < right && nums[left] == loVal) left++;
                }
            }
            return res;        
        }else{
            for(int i = start; i < nums.size(); i++){
                vector<vector<int>> tmp = nSumTarget(nums, n-1, i+1, target-nums[i]);
                for(vector<int>& t : tmp){
                    t.push_back(nums[i]);
                    res.push_back(t);
                }
//这里的去重和twosum中不同，不好理解
//              int val = nums[i];
//              while(i < nums.size()-1 && nums[i] == val) i++;         
                while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
        }
        return res;  
    }
};
// @lc code=end

