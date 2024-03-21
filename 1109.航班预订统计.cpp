/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n, 0);
        Difference diff(nums);

        for(auto booking: bookings){
            int i = booking[0]-1;
            int j = booking[1]-1;
            int val = booking[2];
            diff.increment(i, j, val);
        }
        return diff.result();
    }
};
// @lc code=end

