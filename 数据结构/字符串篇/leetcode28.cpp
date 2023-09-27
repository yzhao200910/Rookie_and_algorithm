//
// Created by 16537 on 2023/6/12.
//
//#include <iostream>
#include <vector>
#include <string>
/**
题目：找出字符串中第一个匹配项的下标
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle
字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
题目来源于leetcode 可以用暴力匹配，源码可以去看代码随想录或者leetcode官网的一些题解
由于对j取值不同衍生出三种不同的写法 ，这里前缀表（不减一）
这篇注重kmp算法解决

 */

using namespace std;
class Solution{
public:
     //next数组的构建，思想最长前后缀和
     //举个例子 aabca 那么他的next数组为0，1，0，0，1
              // acbac 0,0.0,1,2
     void getNext(int* next, const string& s){
         int j=0;
         next[0]=0;
         for(int i=1;i<s.size();i++){
             while(j>0&&s[i]!=s[j]){
                 j=next[j-1];
             }
             if(s[i]==s[j]){
                 j++;
             }
             next[i]=j;
         }

     }
     /**next数组的作用， 以列子为例
      * Haystack:aabbaabbaac
      * needle:aabbaac  next数组值;0100120
      * 在index为6发生不匹配，那么指向aabbaac字符串的指针就要回到next[j-1]所对应值的地方，而指向Haystack的指针还是接着走和这个needle[next[j-1]]再比较
      */
     int strSTR(string haystack,string needle){
         if(needle.size()==0){
             return 0;
         }
         int next[needle.size()];
         getNext(next,needle);
         int j=0;
         for(int i = 0; i < haystack.size(); i++){
             while(j > 0 && haystack[i] != needle[j]) {
                 j = next[j - 1];
             }
             if (haystack[i] == needle[j]) {
                 j++;
             }
             if (j == needle.size() ) {
                 return (i - needle.size() + 1);
             }
         }
         return -1;
     }
};