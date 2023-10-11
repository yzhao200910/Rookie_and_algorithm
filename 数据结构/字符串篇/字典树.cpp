//
// Created by 16537 on 2023/10/10.
//

#include <iostream>

using namespace std;

const int N =100010;

int son[N][26]={0}, cnt[N], idx;

class tree_ {
public:
    void insert(char str[]) {//插入字符，也就是创建字典树的过程
        int p = 0;
        for (int i = 0; str[i]; i++) {
            int u = str[i] - 'a';//哈希映射，每个字符对应编码的数字是不同的
            //用字符去减a就是对a的偏移量
            if (!son[p][u]) son[p][u] = ++idx;//更新层数
            p = son[p][u]; //首先这是二维数组，里面的元素对应每个字符串第一个字母的位置
        }
        cnt[p]++;//对结尾进行标记
    }
    int query(char str[]){ //查找字符串
        int p=0;
        for (int i = 0; str[i]; i++) {
         int u=str[i] -'a';//第一次循环的情况：得到是否有第一个字母存在
         if(!son[p][u]) return 0;//没找到
         p=son[p][u];

        }
        return cnt[p];
    }
    //查找前缀
    bool prefix(char str[]){
        int p = 0;
        for (int i = 0; str[i]; i++) {
            int u = str[i] - 'a';//哈希映射，每个字符对应编码的数字是不同的
            //用字符去减a就是对a的偏移量
            if (!son[p][u]) return false;//更新层数
            p = son[p][u]; //首先这是二维数组，里面的元素对应每个字符串第一个字母的位置
        }
        return true;

    }
};