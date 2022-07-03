/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                res[0] = map[nums[i]];
                res[1] = i;
                return res;
            }
            map[target - nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

