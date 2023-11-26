//
// Created by 16537 on 2023/11/21.
//
/**
*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
*字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
*
 * 思路：将每个字符串都排序，变成哈希表的key，未排序状态作为value
*/
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>>hash;
        vector<vector<string>> re;

        for(auto &str:strs){
            string nstr=str;
            sort(nstr.begin(),nstr.end());//这一步很关键
            hash[nstr].push_back(str);//nstr排序好的作为key，str未排序的作为value
        }
        for(auto str:hash){
            re.push_back(str.second);
        }
        return re;

    }
};