/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (46.92%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 48K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * 输出: 
 * "apple"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * 输出: 
 * "a"
 * 
 * 
 * 说明:
 * 
 * 
 * 所有输入的字符串只包含小写字母。
 * 字典的大小不会超过 1000。
 * 所有输入的字符串长度不会超过 1000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // string findLongestWord(string s, vector<string>& d) {
    //     string::iterator s_iter, dv_iter;
    //     vector<string>::iterator d_iter = d.begin();
    //     int longestCount = 0;
    //     string result = "", tmp;
    //     while(d_iter != d.end()){
    //         tmp = *d_iter;
    //         dv_iter = tmp.begin();
    //         s_iter = s.begin();
    //         int count = 0;
    //         while(dv_iter != tmp.end() && s_iter != s.end()){
    //             if(*dv_iter == *s_iter){
    //                 count++;
    //                 dv_iter++;
    //             }
    //             s_iter++;
    //         }
    //         if(count > longestCount){
    //             longestCount = count;
    //             result = *d_iter;
    //         }
    //     }
    //     return result;
    // }
    bool isWord(string pattern, string &srcStr){
        int i=0, j=0, pLen=int(pattern.size()), sLen=int(srcStr.size());
        while(i<pLen && j<sLen){
            if(pattern[i]==srcStr[j]){
                ++i;
                ++j;
            }
            else
                ++i;
        }
        
        if(j<sLen)
            return false;
        else
            return true;
    }    
   
    static bool compare(string &a, string &b){
        if(a.size() > b.size())
            return true;    
        else if(a.size() == b.size()){
            if(a < b)
                return true;
            else
                return false;
        }      
        else
            return false;
    }
  
    string findLongestWord(string s, vector<string>& d) {
        if(s.size() == 0 || d.size() == 0)
            return "";
                
        sort(d.begin(), d.end(), compare);
        
        for(int i = 0;i < d.size(); ++i){
            if(isWord(s, d[i])){
                return d[i];
            }
        }
        
        return "";
    }
};
// @lc code=end

