//
// Created by 16537 on 2023/11/4.
//
/**题目全排列：
 *给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。



示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
 *思路：dfs+回溯，直接套排列模板即可
 */
#include <vector>
using namespace std;
class Solution {
public:
//int u;
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> re;
    vector<vector<int>> permute(vector<int>& nums) {
        st=vector<bool>(nums.size());

        dfs(nums,0);

        return re;
    }
    void dfs(vector<int> &nums,int u){
        if(u==nums.size()){
            re.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!st[i]){
                st[i]=true;
                path.push_back(nums[i]);
                dfs(nums,u+1);
                st[i]=false;
                path.pop_back();
            }
        }
    }

};