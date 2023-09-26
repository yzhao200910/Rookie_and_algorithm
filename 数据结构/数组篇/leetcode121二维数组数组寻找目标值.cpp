//
// Created by 16537 on 2023/8/26.
//
#include <iostream>
#include <vector>
/**
 * 题目大意：m*n 的二维数组 plants 记录了园林景观的植物排布情况，具有以下特性：
每行中，每棵植物的右侧相邻植物不矮于该植物；
每列中，每棵植物的下侧相邻植物不矮于该植物
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
2368
4589
591012
 *主要思路：根据题意：二维数组中的数组都属有序的
 * 而且二维数组第一行的第一个元素永远小于后面行数的第一个元素
 * 第一我们可以先让要找的值先和每个数组里面第一个元素比较，如果大于并小于这行数组的最大值，
 * 那么这个数就有可能在这一行数组之中，就不要暴力的一个个去找
 * 第二：每一行都是有序的，那么在有序数组中找一个值，肯定会想到二分查找吧
 *
 */
using namespace std;
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if (plants.empty() || plants[0].empty()) return false;//无元素返回false

        int m = plants.size();
        int n = plants[0].size();

        for (int i = 0; i < m; i++) {
            int first = 0;
            int right = n - 1;
                //如果找到就是用二分查找找要找值
            if (plants[i][first] <= target && target <= plants[i][right]) {
                while (first <= right) {
                    int mid = (first + right) / 2;
                    if (plants[i][mid] == target) {
                        return true;
                    } else if (plants[i][mid] < target) {
                        first = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
