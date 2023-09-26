#include <iostream>
#include <vector>
#include <algorithm>
/**
 * leetcode 128题， 求连续的最长子序列的长度
 * 本题主要利用的思想是双指针
 * 用一个值去记入出现连续子序列的长度
 * 在用一个值去更新子序列的长度
 */
using namespace std;
class Solution {
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
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main(){
    vector<int> nums(0,1);
    int len=0;
    cin>>len;
    int n;
    for(int i=0;i<len;i++){
        cin>>n;
        nums.push_back(n);
    }

    Solution solution;
    int s=solution.longestConsecutive(nums);
    cout<<s<<endl;

}