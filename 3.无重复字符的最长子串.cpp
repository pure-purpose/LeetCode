/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (38.85%)
 * Likes:    7765
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 4.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char> set;
        // int ans = 0;
        // for (auto c : s)
        // {
        //     if (set.find(c) !=set.end())
        //     {
        //         ans = max(ans, (int) set.size());
        //         set.erase(set.begin(),set.find(c));
        //         set.erase(c);
        //     }
        // set.insert(c);
        // }
        std::unordered_map<char, int> map;
        int ans = 0;
        int last_repeat = 0;
        size_t len = s.size();
        for(int i = 0; i< len; i++)
        {
            if(map.find(s[i]) != map.end())
            {
                ans = std::max(ans, (int)map.size());
                for(int j = last_repeat, last_repeat = map[s[i]]; j < last_repeat; j++)
                {
                    map.erase(s[j]);
                }
            }
            map[s[i]] = i;
        }
        ans = max(ans, (int) map.size());
        return ans;
        // int ans = 0, i = 0, j = 0;
        // while (i < s.size() && j < s.size()) {
        //     if set.find(s[j]) ==set.end()) {
        //        set[s[j]] = j;
        //         j++;
        //         ans = max(ans, j - i);
        //     } else {
        //         i =set[s[j]] + 1;
        //        set[s[j]] = j;
        //     }
        // }
        // return ans;
    }
};
// @lc code=end

