//
// Created by 16537 on 2023/12/11.
//
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        int res=1;
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int>&b){
            return a[1]<b[1];
        });
        int x=points[0][1];
        for(int i=1;i<points.size();i++){//统计无交集区间得个数

            if(points[i][0]>=x){
                res++;
                x=points[i][1];
            }

        }
        return points.size()- res;
    }
};