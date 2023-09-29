//
// Created by 16537 on 2023/9/29.
//
#include<vector>
#include <memory>
using namespace std;
// Definition for a binary tree node.
/**这道题来自剑指offer面试题7，重新构造二叉数，这道题与leetcode106题目大意相同，解法也差不多
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建二叉树
 *前序遍历;中左右，中序遍历：左中右
 *例子：前序遍历数组{1，2，4，7，3，5，6，8} 中序遍历数组{4，7，2，1，5，3，8，6}
 *剑指offer上有这棵树的图，观察这两数组，你会发现前序的第一个元素是根节点，根节点的索引位置
 * 在中序遍历数组的里面就是分割左边和右边的分界线。而再看前序遍历，去掉第一个元素（已经成为节点的值）247 | 3568，发现左右的第一个元素，也是根节点下面左右节点的对应的值，这个分界的划分也是靠中序数组产生的
 *preface=[prefaceBegin prefaceEnd]   inorder=[inorderBegin inorederEnd]
 */
struct TreeNode {
       int val;
        TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
class Solution {
    TreeNode* traversal(std::vector<int> &preface, int prefaceBegin, int prefaceEnd, vector<int> &inorder, int inorderBegin,int inorderEnd) {
        if (prefaceBegin == prefaceEnd) return nullptr;
        int rootvalue=preface[prefaceBegin];//前序数组的第一个值就是根节点的值，也是左子树和右子树的根的值

       TreeNode* node=new TreeNode(rootvalue);
       //unique_ptr<TreeNode>node= make_unique<TreeNode>(rootvalue);
       // 而右值引用呢，他创建一个指针指向这块区域，同时将原来的指针指向空，这不少了一部分占内存的资源
        int split_number;
        for(split_number=inorderBegin;split_number<=inorderEnd;split_number++){
            if(inorder[split_number]==rootvalue) break;
        }
        //开始分割数组
        //对于中序数组，摒弃index==split_number的值，分成两块，其实这里已经为左树与右树节点对应的值就已经分成左右了
        //左边 左闭右开
        int leftinorderBeign=inorderBegin;
        int leftinorderEnd=split_number;
        //左边 左闭右开
        int rightinorderBegin=split_number+1;
        int rightinorderEnd=inorderEnd;
        //对于前序数组分割
        int leftprefaceBegin=prefaceBegin+1;//跳过第一个数，已经成为对应位置节点的值
        int leftprefaceEnd=prefaceBegin+split_number-inorderBegin;
        //右边
        int rightprefaceBegin=prefaceBegin+split_number-inorderBegin;
        int rightprefaceEnd=prefaceEnd;


        node->left= traversal(preface,leftprefaceBegin,leftprefaceEnd,inorder,rightinorderBegin,rightinorderEnd);
        node->right= traversal(preface,rightprefaceBegin,rightprefaceEnd,inorder,rightinorderBegin,rightinorderEnd);
        return node;
    }

};