/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (49.05%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    243.2K
 * Total Submissions: 495.9K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出：[1,2,2,3,5,6]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^9 
 * nums1.length == m + n
 * nums2.length == n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0){
            nums1.assign(nums2.begin(), nums2.end());
        }
        int nums1_pointer = m - 1, nums2_pointer = n - 1, nums1_index = m + n - 1;
        while (nums1_pointer >= 0 && nums2_pointer >= 0){
            if (nums1[nums1_pointer] > nums2[nums2_pointer]){
                nums1[nums1_index--] = nums1[nums1_pointer--];
            }
            else {
                nums1[nums1_index--] = nums2[nums2_pointer--];
            }
        }
        while (nums2_pointer >= 0){
            nums1[nums1_index--] = nums2[nums2_pointer--];
        }
    }
};
// @lc code=end

