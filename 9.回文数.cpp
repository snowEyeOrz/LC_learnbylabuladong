/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string org=to_string(x);
        string rev=org;
        reverse(rev.begin(),rev.end());
        return (org==rev)?true:false;
    }
};
// @lc code=end

