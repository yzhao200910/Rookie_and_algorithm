//
// Created by 16537 on 2023/11/21.
//
/**
 * 判断子序列 392
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）
 字符而不改变剩余字符相对位置形成的新字符串。
 （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 来源leetcode：https://leetcode.cn/problems/is-subsequence/?envType=study-plan-v2&envId=top-interview-150
 */
#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slength=s.size(),tlength=t.size();
        int i=0,j=0;
        while(i<slength&&j<tlength){
            if(s[i]==t[j]){//如果遇到相同指向子序列的指针移动
                i++;
            }
            j++;
        }
        if(i==slength)return true;//如果i等于子序列的长度，代表子序列中所有的元素被有序的遍历了
        return false;
    }
};
