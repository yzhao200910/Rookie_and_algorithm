//
// Created by 16537 on 2023/9/25.
//
#include <iostream>
#include <vector>
/**
 * 主要思想
 *
 *
 *
 */
using namespace std;
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if (plants.empty() || plants[0].empty()) return false;

        int m = plants.size();
        int n = plants[0].size();

        for (int i = 0; i < m; i++) {
            int first = 0;
            int right = n - 1;

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
