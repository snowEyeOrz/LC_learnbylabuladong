/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Difference {
private:
    vector<int> diff;
public:
    Difference(vector<int>& nums) {
        diff.resize(nums.size());
        diff[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i-1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if(j + 1 < diff.size()){
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums;
        nums.resize(1001);
        Difference diff(nums);

        for(auto trip:trips){
            diff.increment(trip[1],trip[2]-1,trip[0]);
        }
        vector<int> res = diff.result();
        for(auto num:res){
            if(num > capacity){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

