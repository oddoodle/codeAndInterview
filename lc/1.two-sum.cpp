/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
/*
#题目描述
给定一个整数组nums和一个目标数target，
在数组里找到相加等于target的两个数的下标并返回；
数组不一定是有序的，假设输入一定有解，且唯一，同一个位置的数字不能用两次
#知识点
array;map;
#解题思路
暴力搜索的方法的时间复杂度为n^2,考虑用空间换时间
使用map存储已经遍历过的数，key为差值，值为原来的索引值
*/

#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> diffMap;
        vector<int> result;
        for(int i=0;i<=nums.size()-1;i++)
        {
            int diff = target - nums[i];
            map<int,int>::iterator iter = diffMap.find(diff);
            if(iter != diffMap.end())//找到了
            {
                result.push_back(iter->second);
                result.push_back(i);
                break;
                
            }
            else
            {
                diffMap[nums[i]] = i;
            }
        }
        return result;
        

    }
};
// @lc code=end

