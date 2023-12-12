//
// Created by 16537 on 2023/11/21.
//

/**
 * 盛最多水的容器 leetcode 11
* 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。



 思路：高度决定一切，其实就是找两边高度差的最小，使得与底边相乘去打最大值
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int re= 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            re = max(re, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return re;
    }
};

