/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (45.29%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 77.8K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2)
            return size;
        vector<int> candiess(size, 1);

        for (int i = 0; i < size - 1; i++){
            if (ratings[i] < ratings[i + 1])
                candiess[i + 1] = candiess[i] + 1;
        }
        for (int i = size - 1; i > 0; i--){
            if (ratings[i] < ratings[i - 1])
                candiess[i - 1] = max(candiess[i - 1], candiess[i] + 1);
        }

        // int res = 0;
        // for (int i = 0; i < size; i++)
        //     res += candiess[i];
        return accumulate(candiess.begin(), candiess.end(), 0);
    }
};
// @lc code=end

