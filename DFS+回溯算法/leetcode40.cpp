//
// Created by 16537 on 2023/12/15.
//
/**
* 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。



示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<bool> st;
    vector<int>path;//存放一条路径
    vector<vector<int>> re;//结果的集合
    int sum;
    int count;
public:
    vector<vector<int>> combinationSum2 (vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        st=vector<bool>(candidates.size());
        count=0;
        sum=target;
        dfs(0,candidates);
        return re;
    }

    void dfs(int start,vector<int>& nums){
        // int count=0;
        if(count==sum){
            re.push_back(path);
        }
        if(start==nums.size()||count>sum){
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(!st[i]){
                if(i>start&&nums[i]==nums[i-1]) continue;//去开头元素重复的问题
                st[i]=true;
                count+=nums[i];
                path.push_back(nums[i]);
                dfs(i+1,nums);
                st[i]=false;
                count-=nums[i];
                path.pop_back();
            }
        }

    }
};
