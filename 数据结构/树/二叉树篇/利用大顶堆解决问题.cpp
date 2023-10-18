//
// Created by 16537 on 2023/10/17.
//
/**
* 题目来源于leetcode
 *给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你的 起始分数 为 0 。

在一步 操作 中：

选出一个满足 0 <= i < nums.length 的下标 i ，
将你的 分数 增加 nums[i] ，并且
将 nums[i] 替换为 ceil(nums[i] / 3) 。
返回在 恰好 执行 k 次操作后，你可能获得的最大分数。

向上取整函数 ceil(val) 的结果是大于或等于 val 的最小整数。
 *
*/
#include<queue>
using namespace std;
class Solution {
public:

    int len;
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> max_heap(less<int>(),move(nums));//将nums的权限的转移给堆，减少复制
        long sum=0;
        while(k--){
            int x=max_heap.top();//
            sum+=x;
            max_heap.pop();
            max_heap.push((x+2)/3);//如果变得不是最大值就会下沉
        }
        return sum;
    }

};