//
// Created by 16537 on 2023/11/21.
//

/**
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *leetcode 128
 */

//解法一，哈希表解法，参考官方题解
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
 //解法二双指针
class SOlution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());// 先排序
        int count = 1; // 用于记录当前连续子序列的长度
        int maxCount = 1; // 用于记录最长连续子序列的长度
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) {
                count++;
            } else if (nums[i + 1] != nums[i]) { // 处理重复数字
                count = 1;
            }
            maxCount = max(maxCount, count);//更新他最长子序列的长度
        }
        return maxCount;
    }
};

