//
// Created by 16537 on 2023/9/30.
//
//将链表的值，逆序输出，在不改变链表结构的前提下
//这边是用书上给的思想利用栈去实现，因为栈是先进后出的结构

#include<stack>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class solution{
    vector<int>inverse_order(ListNode *head){
        //首先遍历链表，将链表的每个直插入进这个数组之中
        ListNode *cur=head;
        stack<int> containers;
        vector<int> result;//用于存贮最后的结果
        while(cur){
            containers.push(cur->val);
            cur=cur->next;
        }
        while(!containers.empty()) {
            result.push_back(containers.top());
            containers.pop();
        }
        return result;

    }

};