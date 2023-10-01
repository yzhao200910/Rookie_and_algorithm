//
// Created by 16537 on 2023/9/30.
//
/**
 * 题目介绍：反转链表，也就是每一个前节点与后节点进行交换
 * 主要方法：双指针
 *
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Sultion{
      ListNode* reverseList(ListNode* head) {
            ListNode *prenode=nullptr;
            ListNode * Node=head;
            ListNode * temp;
            while(Node){
                temp=Node->next;
                Node->next=prenode;
                prenode=Node;
                Node=temp;
            }
             return prenode;
      }

  };
  //递归的写法
  class solution {
  public:
      ListNode* reverseList(ListNode* head) {
          return reverse(head,nullptr);
      }
      ListNode* reverse(ListNode *cur,ListNode* pre){
          if(!cur){
              return pre;
          }
          ListNode *temp=cur->next;
          cur->next=pre;
          return reverse(temp,cur);
      }
  };
