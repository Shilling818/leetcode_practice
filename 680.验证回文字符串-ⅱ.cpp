/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (39.92%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    58.1K
 * Total Submissions: 145.5K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool judge(string s, int left, int right, int modify){
        while (left < right){
            if (s[left] != s[right]){
                // modify 即将加1
                if (modify >= 1)
                    return false;
                return judge(s, left + 1, right, modify + 1) || judge(s, left, right - 1, modify + 1);
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.length() <= 2)
            return true;
        int front = 0, back = s.length() - 1;
        return judge(s, front, back, 0);
    }

    
};
// @lc code=end

