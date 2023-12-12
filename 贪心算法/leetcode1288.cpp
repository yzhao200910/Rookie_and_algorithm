//
// Created by 16537 on 2023/12/11.
//
/**
 * 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。



示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];});
        int re=a.size(),r=0;
        for(auto &x:a){
            if(x[1]<=r)re--;
            r=max(r,x[1]);
        }
        return re;

    }
};