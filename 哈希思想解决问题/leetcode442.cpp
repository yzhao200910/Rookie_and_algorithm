//
// Created by 16537 on 2023/9/24.
//
#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;
/**
* 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
*/
//这种不符合要求申请了额外空间
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if(it->second==2){
                result.push_back(it->first);
            }


        }
        return result;
    }
private:
    unordered_map<int, int> umap;
    vector<int> result;
};
/**
 * 原地哈希
 *
 */
class solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for (auto& num : nums) {
            int x = (num - 1) % n;//通过余数找到他们本应该在什么位置。
            nums[x] += n;//原地哈希
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 2 * n) ret.push_back(i + 1);//如果存在重复（num-10%)会在相同位置实行加法两次，
            //无重复的通过加法是无法突破2*n的
        }
        return ret;
    }
};

