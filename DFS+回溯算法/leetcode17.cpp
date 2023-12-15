//
// Created by 16537 on 2023/12/15.
//
/**
* 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string>re;
    string str[10]={
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
    };
    string path;
    vector<string> letterCombinations(string digits) {
        if(digits=="")return re;
        dfs(digits,0,path);//path没有用引用，起到回溯作用
        return re;

    }

    void dfs(string&digits,int u,string path){
        if(u==digits.size()) re.push_back(path);
        else{
            for(auto c:str[digits[u]-'0'])//起到与别的数字代表的字符去组合
                dfs(digits,u+1,path+c);
        }
    }
};