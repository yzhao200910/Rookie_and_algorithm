//
// Created by 16537 on 2023/11/21.
//
/**
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend]
 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。 *
 *
 * 来源leetcode 452
 *
 * 思路：一种模型：区间选点模型，贪心选右端点
        只有后一个区间的左端点大于前一个区间右端点，那么次数加一
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=1;
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int>&b){//以右端点排序
            return a[1]<b[1];
        });
        int x=points[0][1];
        for(int i=1;i<points.size();i++){
            //只有后一个区间的左端点大于前一个区间右端点，那么次数加一
            if(points[i][0]>x){
                res++;
                x=points[i][1];
            }

        }
        return res;

    }
};