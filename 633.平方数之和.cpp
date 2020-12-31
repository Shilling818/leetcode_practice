/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (34.46%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 97.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例 2：
 * 
 * 输入：c = 3
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：c = 4
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：c = 2
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：c = 1
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0)
            return false;
        // signed integer overflow
        // int sqrt_c = floor(sqrt(c));
        // int left = 0, right = sqrt_c;
        int sqrt_c = floor(sqrt(c));
        long left = 0, right = sqrt_c;
        int sumLR = 0;
        while (left <= right){
            sumLR = left * left + right * right;
            if (sumLR > c)
                right--;
            else if (sumLR < c)
                left++;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end

