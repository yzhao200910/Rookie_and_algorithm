//
// Created by 16537 on 2023/9/26.
//
//#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
/**  题目描述：来自leetcode 编号977 :有序数组的平方
 * 题目大意：给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *解题思路：首先这是一个有序数组，在平方以后，最大值只会分布在数组的两头，这时我们有双指针来解决，一个指向前端，一个指向后端
 * 核心要点：首先如果数组里面全是正数，平方和也没啥影响，但是存在负数，是不是只要比较平方后的负数和正数，
 * 那么自然而然可以想到要一个指针指向前端，一个指向后端（负数平方后的结果，越靠前说明这个负数平方后越大，就要和正数最后的比，也就是之前的最大值比较）
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);//来接收结果
        int k=nums.size()-1;//由于平方过后的的负数有可能大于后面的数，所以要从result的后面开始插
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]*nums[i]>nums[j]*nums[j]){//只有前面的大于后面的，指向前面的指针才能移动
                result[k--]=nums[i]*nums[i];
                i++;
            }else{
                result[k--]=nums[j]*nums[j];//如果后端的数大，那么原来位置的还是这个数的平方
                j--;
            }
        }
        return result;
    }
};