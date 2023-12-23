# 刷题笔记

## **借鉴和题目来源：**

例题题目来自于leetcode，acwing,解题思路有些借鉴y总和代码随想录，算法导论等

## **Trie树（字典树）**

基本用法：1：快速高效存储，查找字符串的集合的数据结构

![image-20231010201653732](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231010201653732.png)

存储一个单词后，都要在结尾打标记

代码思路：

```c++
const int N =100010;
/**
trie树那里，觉得可以稍微补充下怎么用数组去建树，一开始以为[N][26]的第一维度是树的层数；现在搞懂了，一维是结点总数，而结点和结点之间的关系（谁是谁儿子）存在第二个维度，比如[0][1]=3, [0]表示根节点，[1]表示它有一个儿子‘b’,这个儿子的下标是3；接着如果有一个[3][2]=8 ; 说明根节点的儿子‘b’也有一个儿子‘c’，这个孙子的下标就是8；这样传递下去，就是一个字符串。随便给一个结点][x][y], 并不能看出它在第几层，只能知道，它的儿子是谁。【菜鸡互助
**/

int son[N][26], cnt[N], idx;

class tree_ {
public:
    void insert(char str[]) {//插入字符，也就是创建字典树的过程
        int p = 0;
        for (int i = 0; str[i]; i++) {
            int u = str[i] - 'a';//哈希映射，每个字符对应编码的数字是不同的
            //用字符去减a就是对a的偏移量
            if (!son[p][u]) son[p][u] = ++idx;//
            p = son[p][u]; //
        }
        cnt[p]++;//对结尾进行标记
    }
    int query(char str[]){ //查找字符串
        int p=0;
        for (int i = 0; str[i]; i++) {
         int u=str[i] -'a';//第一次循环的情况：得到是否有第一个字母存在
         if(!son[p][u]) return 0;//没找到
         p=son[p][u];

​        }
​        return cnt[p];
​    }
};
```

```c++
class Trie {

public:

  /** Initialize your data structure here. */

  Trie() {

​    // 初始化数据结构

​    son = vector<vector<int>>(26, vector<int>(26, 0));

​    cnt = vector<int>(26, 0);

​    idx = 0;

  }

  

  /** Inserts a word into the trie. */

  void insert(string word) {

​    int p = 0;

​    for (int i = 0; i < word.size(); i++) {

​      int u = word[i] - 'a'; // 获取字母的映射位置

​      if (!son[p][u]) {

​        son[p][u] = ++idx;

​      }

​      p = son[p][u];

​    }

​    cnt[p]++;

  }

  

  /** Returns if the word is in the trie. */

  bool search(string word) {

​    int p = 0;

​    for (int i = 0; i < word.size(); i++) {

​      int u = word[i] - 'a'; // 获取字母的映射位置

​      if (!son[p][u]) {

​        return false;

​      }

​      p = son[p][u];

​    }

​    if (cnt[p]) {

​      return true;

​    } else {

​      return false;

​    }

  }

  

  /** Returns if there is any word in the trie that starts with the given prefix. */

  bool startsWith(string prefix) {

​    int p = 0;

​    for (int i = 0; i < prefix.size(); i++) {

​      int u = prefix[i] - 'a'; // 获取字母的映射位置

​      if (!son[p][u]) {

​        return false;

​      }

​      p = son[p][u];

​    }

​    return true;

  }

private:

  vector<vector<int>> son; // son[p][u] 表示第 p 个节点的第 u 个儿子节点的编号

  vector<int> cnt; // cnt[p] 表示第 p 个节点对应的单词数

  int idx;

};
```

```c++
class Trie {
private:
    struct TrieNode //26叉树结构体，结构体中包含它自己，即每一个子树又是一个26叉树
    {
        bool isWord;
        vector<shared_ptr<TrieNode>> children;
        TrieNode():isWord(false), children(26, nullptr){}   //成员列表初始化
    };

    shared_ptr<TrieNode> findPrefix(string& prefix)         //查找前缀的方法
    {
        auto node = root;
        for (int i = 0; i < prefix.length() && node != nullptr; ++ i)
        {
            node = node->children[prefix[i] - 'a'];
        }
        return node;            //若是前缀就返回最后一个字母所在的node，否则返回nullptr
    }
    
    shared_ptr<TrieNode> root;  

public:
    Trie() {
        root = make_shared<TrieNode>();     //初始化智能指针
    }
    

    //往前缀树中插入单词
    void insert(string word) {
        auto node = root;           //node为当前节点，从头节开始
        for (auto &ch : word)       //遍历每个字母，若字母对应的节点不存在，则创建它
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                node->children[ch - 'a'] = make_shared<TrieNode>();
            }
    
            node = node->children[ch - 'a'];    //进入到对应的子树节点中，开始下一轮插入
        }
    
        node->isWord = true;        //整个单词遍历完后，将最后一个节点标记为单词结尾
    }
    
    //前缀树中查找单词
    bool search(string word) {
        auto node = findPrefix(word);
        return node != nullptr && node->isWord == true;
    }
    
    //前缀树中查找前缀
    bool startsWith(string prefix) {
        return findPrefix(prefix) != nullptr;
    }

};
```

参考leetcode作者

## **并查集**

1：将两个集合合并

2：询问两个元素是否在一个集合当中

以上问题利用并查集可以做到O(1)的时间复杂度

<img src="C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231010220433015.png" alt="image-20231010220433015" style="zoom:50%;" />基本原理：每个集合用一颗树来表示。树根的编号就是整个集合的编号。每个节点存储他的父节点，p[x]表示x的父节点

问题1:如何判断树根 p[x]==x //p[x]为根节点也就是元素的编号

问题2：如何求x的集合编号：while(p[x]!=x) x=p[x]

问题三;如何合并集合：px是X的标号，py是y的集合编号。p[x]=y,将一个树变为另一个数的子树

优化 路径压缩

如果找到x的根节点是元素的编号，将他的所有子节点都指向元素的编号(也就是根节点)

image-20231010224113975

```c++
#include<iostream>

using namespace std;

const int N=100010;
int p[N];//定义多个集合

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    /*
    经上述可以发现,每个集合中只有祖宗节点的p[x]值等于他自己,即:
    p[x]=x;
    */
    return p[x];
    //找到了便返回祖宗节点的值
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(*op=='M') p[find(a)]=find(b);//集合合并操作
        else
        if(find(a)==find(b))
        //如果祖宗节点一样,就输出yes
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}
```

核心：把find函数理解即可

## **堆：手写堆**

两个基本操作 down向下调整 up向上调整

功能：插入一个数：heap[++size]=x; up(size)

求集合当中最小的值  heap[1]

删除最小值。 heap[1]=heap[size]; size--;down(1)

( 技巧，因为是由一维数组去存储的，删除头节点难度太大，那么将最后的去代替最小的，然后减少数组的大小，再让替代的down即可 )

 删除任意元素：heap[k]=heap[size]; size--;down() or up()

修改任意元素:heap[k]=x,down() or up()

堆的结构：一个完全二叉树  

以小顶堆为列

存储：一维数组存储 如图：

![image-20231011213325044](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231011213325044.png)

## **哈希表**

![image-20231012202620923](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231012202620923.png)

解决哈希冲突：

![image-20231012203805805](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231012203805805.png)

设计哈希表; 拉链法

`cons`

```c++
const int N = 19997;

class MyHashSet {
public:
    vector<int> h[N];//每一个h[i]看做一行

    /** Initialize your data structure here. */
    MyHashSet() {

    }

    int find(vector<int>& h, int key) {
        for (int i = 0; i < h.size(); i ++ )
            if (h[i] == key)
                return i;
        return -1;
    }

    void add(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if (k == -1) h[t].push_back(key);//当前坑位处插入
    }

    void remove(int key) {
        int t = key % N;
        int k = find(h[t], key);
        if (k != -1) h[t].erase(h[t].begin() + k);//直接删除即可
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t = key % N;
        int k = find(h[t], key);
        return k != -1;
    }
};

```

字符串哈希：

















## STL使用技巧 ：vector,string 不说

![image-20231013220058675](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013220058675.png)

![image-20231013221358185](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013221358185.png)



![image-20231013222728846](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013222728846.png)

## 位运算：

### 概念理解：

### 例题1：[二进制求和](https://leetcode.cn/problems/add-binary/)

给你两个二进制字符串 `a` 和 `b` ，以二进制字符串的形式返回它们的和。

 

**示例 1：**

```
输入:a = "11", b = "1"
输出："100"
```

**示例 2：**

```
输入：a = "1010", b = "1011"
输出："10101"
```

```c++
 class Solution {

public:

  string addBinary(string a, string b) {

​    reverse(a.begin(), a.end());

​    reverse(b.begin(), b.end());



​    string c;

​    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ ) {

​      if (i < a.size()) t += a[i] - '0';

​      if (i < b.size()) t += b[i] - '0';

​      c += to_string(t % 2);//和为2则进位，但前位置为0

​      t /= 2;//如果此位上两个一，则t在下次进行加时默认为一

​    }



​    reverse(c.begin(), c.end());

​    return c;

  }

};
```

### 例题二：[加一](https://leetcode.cn/problems/plus-one/)

给定一个由 **整数** 组成的 **非空** 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储**单个**数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

**示例 1：**

```
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
```

**示例 2：**

```
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
```

**示例 3：**

```
输入：digits = [0]
输出：[1]
```

```c++
class Solution {

public:

  vector<int> plusOne(vector<int>& a) {

​     reverse(a.begin(), a.end());

​     int t=1;

​     for(auto &x:a){

​       t+=x;

​       x=t;

​       x%=10;//加上t后x的变化

​       t/=10;//是否有进位

​     }

​     if(t) a.push_back(t);

​     reverse(a.begin(),a.end());

​     return a;

  }

};
```

###  例题三：[颠倒二进制位](https://leetcode.cn/problems/reverse-bits/)

**示例 1：**

```
输入：n = 00000010100101000001111010011100
输出：964176192 (00111001011110000010100101000000)
解释：输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
```

**示例 2：**

```
输入：n = 11111111111111111111111111111101
输出：3221225471 (10111111111111111111111111111111)
解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。
```

```c++
//一个技巧：位运算取，对一个32位的二进制，要取他的第几位：n>>i&1,从高位开始取
//将一个数整体向左移动乘二即可或者<<1
class Solution {

public:

  uint32_t reverseBits(uint32_t n) {

​    uint32_t res=0;

​    for(int i=0;i<32;i++){

​      res=res*2+(n>>i&1);

​    }

​    return res;

​    

  }

};
```

###  例题四：[ 数字范围按位与](https://leetcode.cn/problems/bitwise-and-of-numbers-range/)

给你两个整数 `left` 和 `right` ，表示区间 `[left, right]` ，返回此区间内所有数字 **按位与** 的结果（包含 `left` 、`right` 端点）。

 

**示例 1：**

```
输入：left = 5, right = 7
输出：4
```

**示例 2：**

```
输入：left = 0, right = 0
输出：0
```

**示例 3：**

```
输入：left = 1, right = 2147483647
输出：0
```

```c++
//思路：一个区间的与运算的结果等于断点两个数的与运算 
class Solution {

public:

  int rangeBitwiseAnd(int left, int right) {

  

​    int res=0;

​    for(int i=30;i>=0;i--){

​      if((left>>i&1)!=(right>>i&1)) break;

​      if(left>>i&1)res+=1<<i;

​    }

​    return res;



  }

};
```



## **数组篇：**

![img](file:///C:\Users\16537\AppData\Local\Temp\ksohtml5936\wps1.jpg)



### 双指针

常见题：验证回文，判断子序列，盛最多水的容器，三数之和

双指针常见有两种：

一种是两个指针操作一个数组，一个是两个指针分别操作两个

两个指针摆放的位置也有考究，双指针不仅可以处理数组，字符串等，还可以操作链表（比如返回链表倒数第k的元素）



## **链表：**

### 1：LRU缓存

例题：[146. LRU 缓存](https://leetcode.cn/problems/lru-cache/)



请你设计并实现一个满足 [LRU (最近最少使用) 缓存](https://baike.baidu.com/item/LRU) 约束的数据结构。

实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以 **正整数** 作为容量 `capacity` 初始化 LRU 缓存
- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。
- `void put(int key, int value)` 如果关键字 `key` 已经存在，则变更其数据值 `value` ；如果不存在，则向缓存中插入该组 `key-value` 。如果插入操作导致关键字数量超过 `capacity` ，则应该 **逐出** 最久未使用的关键字。

函数 `get` 和 `put` 必须以 `O(1)` 的平均时间复杂度运行。

 

**示例：**

```
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
```



```c++
class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val): key(_key), val(_val), left(NULL), right(NULL) {}
    }*L, *R;
    //哈希表保证了get，put的时间为O(1)
    unordered_map<int, Node*> hash;
    int n;
//双链表保证了在满栈可以做到lru操作，并且插入新元素的时间控制在o(1)
    void remove(Node* p) {
        p->right->left = p->left;
        p->left->right = p->right;
    }

​    void insert(Node* p) {
​        p->right = L->right;
​        p->left = L;
​        L->right->left = p;
​        L->right = p;
​    }

​    LRUCache(int capacity) {
​        n = capacity;
​        L = new Node(-1, -1), R = new Node(-1, -1);
​        L->right = R, R->left = L;
​    }

​    int get(int key) {
​        if (hash.count(key) == 0) return -1;
​        auto p = hash[key];
​        remove(p);
​        insert(p);
​        return p->val;
​    }

​    void put(int key, int value) {
​        if (hash.count(key)) {
​            auto p = hash[key];
​            p->val = value;
​            remove(p);
​            insert(p);
​        } else {
​            if (hash.size() == n) {
​                auto p = R->left;
​                remove(p);
​                hash.erase(p->key);
​                delete p;
​            }
​            auto p = new Node(key, value);
​            hash[key] = p;
​            insert(p);
​        }
​    }
};



/**

 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
   */



/**

 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
   */


```



## **搜索与图论**

### DFS深度优先搜索与BFS宽度优先搜索

![image-20231013232152197](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013232152197.png)

### DFS（暴搜）：回溯和剪枝

最重要的是顺序（树结构）

以全排列这个题为列

![image-20231013233813970](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013233813970.png)







![image-20231013233853692](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231013233853692.png)



#### 例题一：[全排列](https://leetcode.cn/problems/permutations/)

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**示例 2：**

```
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

**示例 3：**

```leetcode
输入：nums = [1]
输出：[[1]]
```

```c++
### dFS：
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

```

#### 例题二[全排列 II

给定一个可包含重复数字的序列 `nums` ，***按任意顺序*** 返回所有不重复的全排列。

 

**示例 1：**

```
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**示例 2：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

#### [](https://leetcode.cn/problems/permutations-ii/)

```c++

相比较普通全排列，多了一步去重，利用哈希表去重

全排列||

`class Solution {`

`public:`

`vector<bool> st;`

`vector<int> path;`

`vector<vector<int>> re;`

`map<vector<int>,int>p;`

  `vector<vector<int>> permuteUnique(vector<int>& nums) {`

​     `st=vector<bool>(nums.size());`



​     `dfs(nums,0);`



​     `return re;` 

  `}`

   `void dfs(vector<int> &nums,int u){`

​    `if(u==nums.size()){`

​      `if(p.count(path)==0){`

​      `re.push_back(path);`

​      `p[path]++;`//计数去重

​      `}`

​      `return ;`

​    `}`

​    `for(int i=0;i<nums.size();i++){`

​      `if(!st[i]){`

​        `st[i]=true;`

​        `path.push_back(nums[i]);`

​        `dfs(nums,u+1);`

​         `st[i]=false;`

​        `path.pop_back();`

​      `}`

​    `}`

  `}`

``  

`};`


```

#### 例题三：[组合](https://leetcode.cn/problems/combinations/)

给定两个整数 `n` 和 `k`，返回范围 `[1, n]` 中所有可能的 `k` 个数的组合。

你可以按 **任何顺序** 返回答案。

 

**示例 1：**

```
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

**示例 2：**

```
输入：n = 1, k = 1
输出：[[1]]
```

```c++
class Solution {

private:

  vector<vector<int>> result;

  vector<int> path;

  void backtracking(int n, int k, int startIndex) {

​    if (path.size() == k) {

​      result.push_back(path);

​      return;

​    }

​    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方

​      path.push_back(i); // 处理节点

​      backtracking(n, k, i + 1);

​      path.pop_back(); // 回溯，撤销处理的节点

​    }

  }

public:



  vector<vector<int>> combine(int n, int k) {

​    backtracking(n, k, 1);

​    return result;

  }

};
```

#### 例题四：[组合总和 II](https://leetcode.cn/problems/combination-sum-ii/)

给定一个候选人编号的集合 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用 **一次** 。

**注意：**解集不能包含重复的组合。 

 示例 1:**

```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**示例 2:**

```
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
```

```c++
class Solution {

  vector<bool> st;

  vector<int>path;//存放一条路径

  vector<vector<int>> re;//结果的集合

  int sum;

  int count;

public:

  vector<vector<int>> combinationSum2 (vector<int>& candidates, int target) {

​    sort(candidates.begin(),candidates.end());

​     st=vector<bool>(candidates.size());

​     count=0;

​     sum=target;

​     dfs(0,candidates);

​     return re;

  }



  void dfs(int start,vector<int>& nums){

​    // int count=0;

​    if(count==sum){

​      re.push_back(path);

​    }

​    if(start==nums.size()||count>sum){

​      return;

​    }

​    for(int i=start;i<nums.size();i++){

​      if(!st[i]){

​        if(i>start&&nums[i]==nums[i-1]) continue;//去开头元素重复的问题

​        st[i]=true;

​        count+=nums[i];

​        path.push_back(nums[i]);

​        dfs(i+1,nums);

​        st[i]=false;

​        count-=nums[i];

​        path.pop_back();

​      }

​    }



  }

};
```



#### 例题五：[电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

 

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```leetcode
输入：digits = "2"
输出：["a","b","c"]
```

```c++
class Solution {

public:

  vector<string>re;

  string str[10]={

​     "", "", "abc", "def",

​      "ghi", "jkl", "mno",

​      "pqrs", "tuv", "wxyz"

  };

  string path;

  vector<string> letterCombinations(string digits) {

​    if(digits=="")return re;

​    dfs(digits,0,path);//path没有用引用，起到回溯作用

​    return re;

​    

  }



  void dfs(string&digits,int u,string path){

​    if(u==digits.size()) re.push_back(path);

​    else{

​      for(auto c:str[digits[u]-'0'])//起到与别的数字代表的字符去组合

​        dfs(digits,u+1,path+c);

​    }

  }

};
```

怎样去理解回溯

![image-20231014065445830](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231014065445830.png)

#### 例题六：[N 皇后](https://leetcode.cn/problems/n-queens/)

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

**n 皇后问题** 研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 `n` ，返回所有不同的 **n 皇后问题** 的解决方案。

每一种解法包含一个不同的 **n 皇后问题** 的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
```

**示例 2：**

```
输入：n = 1
输出：[["Q"]]
```

![image-20231014160510182](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231014160510182.png)

```c++
class Solution {

public:

int n;

vector<bool> col,dg,udg;//对不能出现的位置进行标记

vector<vector<string>> re;

vector<string> path;

  vector<vector<string>> solveNQueens(int _n) {

​      n=_n;

​      col=vector<bool>(n);

​      dg=udg=vector<bool>(n*2);

​      path=vector<string>(n,string(n,'.'));



​      dfs(0);



​      return re;

  }

  void dfs(int u){

​    if(u==n){//u==n,代表这条路可以走通，并且有有效的的值

​      re.push_back(path);

​      return; 

​    }

​    for(int i=0;i<n;i++){

​      if(!col[i]&&!dg[u-i+n]&&!udg[u+i]){

​        col[i]=dg[u-i+n]=udg[u+i]=true;

​        path[u][i]='Q';

​        dfs(u+1);

​        //回溯

​        path[u][i]='.';

​        col[i]=dg[u-i+n]=udg[u+i]=false;

​      }

​    }

  }

};
```

 我现在遇到最多的用dfs去解决的问题无非就两种排列和组合

这两种情况写代码是有技巧的

首先排列下的模板

```c++
//组合，是讲究无序的，只要组合元素相同他们也是一样的
//那么他的dfs怎么写呢
void dfs(int n,vector<int>&nums,int start){
    if()//递归终止条件
     if()//同上
    for(int i=start;i<nums.size();i++){
        if(!st[i]){
            //上锁
            //插入
            dfs(n+1;nums,i+1)
            //回溯
        }
    }
}
排列的代码
    void dfs(int n,vector<int>&nums){
    if()//递归终止条件
     if()//同上
    for(int i=0;i<nums.size();i++){
        if(!st[i]){
            //上锁
            //插入
            dfs(n+1;nums)
            //回溯
        }
    }
}
```





DFS关于分割问题：Leetcode 131分割回文串

解题思路：判断回文（双指针（这里不用对字符串进行处理）），通过深搜去分割



### BFS宽度优先搜索

以走迷宫这道题为列

![image-20231019001738543](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231019001738543.png)

上面画的数字是离起点的位置 

宽搜的基本框架：

![image-20231019002814981](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231019002814981.png)

理解最基本的bfs：二叉树的层序遍历

给出二叉树层序遍历的

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {//每一次while代表着二叉树的一层
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();//记入当前节点信息
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

![image-20231026230144714](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231026230144714.png)



## 图

### 有向图

有向图：边是有方向如;A->B，无向图：如A-B，一般建立A->B和A<-B 可以看成特殊的有向图

### 有向图的存储：

**1:邻接矩阵** 空间复杂度很高，n^n的空间复杂度

**2：邻接表：**就像单链表，有多少个点，就开了多少个单链表，里面的次序是无关的

![image-20231031185133874](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231031185133874.png)



### ![image-20231031185555182](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231031185555182.png)

### 图的遍历：深度与广度

**深搜**

![image-20231031190924760](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231031190924760.png)



```c++
//树与图的深搜
vector<bool> st;//查看这个点有没有被遍历过
void dfs（int n）{//任意挑一个点开始搜
    st[u]=true;//标记一下，遍历过就不用遍历
    for(int i=数组中第一个链表头;i!=空链表;i=下一个存放边的的链表){
        int j=当前点能到地方的一个点
            if(!st[j]) dfs(j);//继续向下搜
    }
}
```

图的一道例题

![image-20231031210709898](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231031210709898.png)

```c++
/**
flood fill算法
如果四条边中出现O，那么肯定是不被包围的，那么从这边界O出发，向四个方向去扩展遇到x那么就是被包围的
[["X","O","X","O","O","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]这种O的旁边还有O那么他也算，因为Dfs是可以标记到的
**/

class Solution {

private:

vector<vector<bool>>st;

int n,m;

int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};//上下左右移动

public:

  void solve(vector<vector<char>>& board) {

​    //初始化图，标记为每个点都未遍历

​    if(board.empty())return;

​    n=board.size(),m=board[0].size();

​    for(int i=0;i<n;i++){

​      vector<bool>temp;

​      for(int j=0;j<m;j++) temp.push_back(false);

​      st.push_back(temp);

​    }



​    for(int i=0;i<n;i++){

​      if(board[i][0]=='O')dfs(i,0,board);

​      if(board[i][m-1]=='O')dfs(i,m-1,board);

​    }

​    for(int i=0;i<m;i++){

​      if(board[0][i]=='O')dfs(0,i,board);

​      if(board[n-1][i]=='O')dfs(n-1,i,board);

​    }

​    for(int i=0;i<n;i++){

​      for(int j=0;j<m;j++){

​        if(!st[i][j]) board[i][j]='X';

​      }

​    }



  }

  void dfs(int x,int y,vector<vector<char>>&board){

​    st[x][y]=true;//在前面只有当前字母为O才能进入函数，也就是对为O的进行标记

​    for(int i=0;i<4;i++){

​      int a=x+dx[i],b=y+dy[i];

​      if(a>=0&&a<n&&b>=0&&b<m&&!st[a][b]&&board[a][b]=='O')

​        dfs(a,b,board);

​    }

  }

};
```

有向图：拓扑序列

有向无环图又被称为拓扑图，一个无环的有向图，至少有一个入度为0的点

![image-20231101200014699](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231101200014699.png)

例题：leetcode207课程表：

![image-20231101220353078](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231101220353078.png)

```c++
class Solution {

public:

  bool canFinish(int n, vector<vector<int>>& pre) {

   vector<vector<int>> g (n);

   vector<int> d(n);//记入入度点

   for(auto &e:pre){

​     int a=e[0],b=e[1];

​     g[a].push_back(b);

​     d[b]++;

   }



   queue<int> q;

   for(int i=0;i<n;i++)

​     if(d[i]==0) q.push(i);

​    int count=0;

   while(q.size()){

​     auto t=q.front();

​     q.pop();

​     count++;

​     for(auto i:g[t])

​       if(--d[i]==0)

​        q.push(i);

   }

   return n==count;

  }

};
```

### 最短路问题：只考虑有向图（无向图只是有向图的特殊情况）

源点：起点， 汇点：重点

![image-20231102203704822](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231102203704822.png)

##### Dijkstra算法

![image-20231102205443932](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231102205443932.png)

第一步：初始化距离，一开始只有1号点是已知，其他不知道那么将未知距离设置为无穷

第二步:确定一个到起点的最短路（未知点中到原点距离最小的点），这是一个迭代的过程

Dijkstra算法处理有向权重图时，权重必须为正，而另外两种可以处理负权重有向图，但是不能出现负环，所谓负环，就是权值总和均为负的环。Dijkstra算法是从一个顶点到其余各顶点的最短路径算法，解决的是有向图中最短路径问题。迪杰斯特拉算法主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止，是一种广度优先的搜索方法。来自acwing hasp大佬的总结

```c++
//稠密图：邻接矩阵
//代码例子

int n,m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(){
    
    memst(dist,0x3f,sizeof(dist))
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j
        st[t]=true;
        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f)  return -1;
    return dist[n];
}
int main(){
    //enter n,m
    memset(g,0x3f,sizeof(g))
    
        while(m--){
            int a,b,c;
            //enter a,b,c
            g[a][b]=min(g[a][b],c);
        }
    int t=dijkstra;
    printf("%d\n",t)
    return 0;
    
}

```

Dijkstra算法---堆优化版

```c++
typedef pair<int, int> PII;

int n; // 点的数量

int h[N], w[N], e[N], ne[N], idx; // 邻接表存储所有边

int dist[N]; // 存储所有点到1号点的距离

bool st[N]; // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1

int dijkstra(){

memset(dist,0x3f,sizeof dist);//距离初始化为无穷大

dist[1]=0;//1->1的节点距离为0

priority_queue<PII,vector<PII>,greater<PII>> heap;//小根堆

heap.push({0,1});//插入距离和节点编号

while(heap.size()){

auto t=heap.top();//取距离源点最近的点

heap.pop();

int ver=t.second,distance=t.first;//ver：节点编号，distance源点距离ver

if(st[ver])continue;//如果距离已经确定，则跳过该点

st[ver]=true;

for(int i=h[ver];i!=-1;i=ne[i])//更新ver所指向的节点距离

{

int j=e[i];

if(dist[j]>dist[ver]+w[i]){

dist[j]=dist[ver]+w[i];

heap.push({dist[j],j});//距离变小，则入堆

}

}

}

if(dist[n]==0x3f3f3f3f)return -1;

return dist[n];

}
```



##### Bellman-ford算法

```c++
int n, m; // n表示点数，m表示边数

int dist[N]; // dist[x]存储1到x的最短路距离

struct Edge // 边，a表示出点，b表示入点，w表示边的权重

{

int a, b, w;

}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。

int bellman_ford()

{

memset(dist, 0x3f, sizeof dist);应用

**SPFA****算法（队列优化的****Bellman-Ford****算法）**

时间复杂度平均情况下 

，最坏情况下 

，n表示点数，m表示边数

dist[1] = 0;

// 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径

中至少存在两个相同的点，说明图中存在负权回路。

for (int i = 0; i < n; i ++ )

{

for (int j = 0; j < m; j ++ )

{

int a = edges[j].a, b = edges[j].b, w = edges[j].w;

if (dist[b] > dist[a] + w)

dist[b] = dist[a] + w;

}

}

if (dist[n] > 0x3f3f3f3f / 2) return -1;

return dist[n];

}


```

##### 例题[787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/)

有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

![image-20231207121104351](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231207121104351.png)

```c++
class Solution {

public:

  const int INF = 1e8;



  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

​    vector<int> dist(n, INF);

​    dist[src] = 0;

​    K ++ ;

​    while (K -- ) {

​      auto cur = dist;

​      for (auto& e: flights) {

​        int a = e[0], b = e[1], c = e[2];

​        cur[b] = min(cur[b], dist[a] + c);

​      }

​      dist = cur;

​    }

​    if (dist[dst] == INF) return -1;

​    return dist[dst];

  }

};
```



##### SPFA算法

注意：他不一定比Bellman算法好，在我们限制最短路要经过哪条变得时候，这个算法是失效的

##### 例题：leetcode743：网络延迟

```c++
const int N = 110, M = 6010, INF = 0x3f3f3f3f;

//邻接表，这是一个稀疏图

int h[N], e[M], w[M], ne[M], idx;

int dist[N];

bool st[N];



class Solution {

public:

//添加

  void add(int a, int b, int c) {

​    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;

  }



  void spfa(int start) {

​    queue<int> q;

​    q.push(start);

​    memset(dist, 0x3f, sizeof dist);

​    dist[start] = 0;

​    while (q.size()) {

​      int t = q.front();

​      q.pop();

​      st[t] = false;

​      for (int i = h[t]; ~i; i = ne[i]) {

​        int j = e[i];

​        if (dist[j] > dist[t] + w[i]) {

​          dist[j] = dist[t] + w[i];

​          if (!st[j]) {

​            q.push(j);

​            st[j] = true;

​          }

​        }

​      }

​    }

  }



  int networkDelayTime(vector<vector<int>>& times, int n, int k) {

​    memset(h, -1, sizeof h);

​    idx = 0;

​    for (auto& e: times) {

​      int a = e[0], b = e[1], c = e[2];

​      add(a, b, c);

​    }

​    spfa(k);

​    int res = 1;

​    for (int i = 1; i <= n; i ++ ) res = max(res, dist[i]);

​    if (res == INF) res = -1;

​    return res;

  }

};
```

## 矩阵

### 例题1：[螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

给你一个 `m` 行 `n` 列的矩阵 `matrix` ，请按照 **顺时针螺旋顺序** ，返回矩阵中的所有元素。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```

### 例题二：[螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

给你一个正整数 `n` ，生成一个包含 `1` 到 `n2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

```
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

**示例 2：**

```
输入：n = 1
输出：[[1]]
```

```c++
class Solution {
public:
//首先我们要保证循环条件的一致性，整个一个while循环代表着转一整圈
//而四个for循环分别对应四条边上的赋值操作
    vector<vector<int>> generateMatrix(int n) {
     vector<vector<int>>res(n,vector<int>(n,0));//定义和初始化数组
     int x=0,y=0;//定义二维数组的x与y
     int offset=1;//用于与收缩
     int j,i;
     int mid=n/2;
     int count=1;
     int loop=n/2;
     while(loop--){// n/2代表转几圈，如何去理解自己画图
        i=x;
        j=y;
        for(j=y;j<n-offset;j++){//循环第一条边
            res[x][j]=count++;
        }
        for(i=x;i<n-offset;i++){//右边竖边
            res[i][j]=count++;
        }
        for(;j>y;j--){
            res[i][j]=count++;
        }
        for(;i>x;i--){
            res[i][j]=count++;
        }
        y++;
        x++;
        offset+=1;
        if(n%2){
        res[mid][mid]=count;
        }

    }
      return res;

}
};
```

```c++
class Solution {

public:

  vector<vector<int>> generateMatrix(int n) {

​    vector<vector<int>> res(n, vector<int>(n));

​    vector<vector<bool>> st(n, vector<bool>(n, false));

​    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};



​    for (int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++) {

​      res[x][y] = i;

​      st[x][y] = true;

​      int a = x + dx[d], b = y + dy[d];

​      if (a < 0 || a >= n || b < 0 || b >= n || st[a][b]) {

​        d = (d + 1) % 4;

​        a = x + dx[d], b = y + dy[d];

​      }

​      x = a, y = b;

​    }

​    return res;

  }



};
```

### 例题三：[48. 旋转图像](https://leetcode.cn/problems/rotate-image/)

给定一个 *n* × *n* 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在**[ 原地](https://baike.baidu.com/item/原地算法)** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)

```
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

```c++
class Solution {

public:

  //先按照对角线对称交换 

  //再按照中线交换

  void rotate(vector<vector<int>>& m) {

​    int n=m.size();

​    for(int i=0;i<n;i++){

​      for(int j=0;j<i;j++)

​        swap(m[i][j],m[j][i]);

​    }

​    for(int i=0;i<n;i++){

​      for(int j=0,k=n-1;j<k;j++,k--)

​        swap(m[i][j],m[i][k]);

​    }



  }

};
```

### 例题四[73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)

给定一个 `*m* x *n*` 的矩阵，如果一个元素为 **0** ，则将其所在行和列的所有元素都设为 **0** 。请使用 **[原地](http://baike.baidu.com/item/原地算法)** 算法**。**



 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)

```
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)

```
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

```c++
class Solution {

public:

  void setZeroes(vector<vector<int>>& matrix) {

​    int n=matrix.size(),m=matrix[0].size();

​    int x0=1,y0=1;

​    for(int i=0;i<m;i++)

​      if(!matrix[0][i])x0=0;

​    for(int i=0;i<n;i++)

​      if(!matrix[i][0])y0=0;

​    

​    for(int i=1;i<n;i++){

​      for(int j=1;j<m;j++){

​        if(!matrix[i][j]){

​          matrix[i][0]=0;

​          matrix[0][j]=0;

​        }

​      }

​    }

​    for(int i=1;i<n;i++){

​      if(!matrix[i][0]) 

​      for(int j=1;j<m;j++){

​        matrix[i][j]=0;

​      }

​    }



​    for(int i=1;i<m;i++){

​      if(!matrix[0][i]) 

​      for(int j=1;j<n;j++){

​        matrix[j][i]=0;

​      }

​    }

​    if(!x0){

​      for(int i=0;i<m;i++)

​        matrix[0][i]=0;

​    }

​    if(!y0){

​      for(int j=0;j<n;j++)

​        matrix[j][0]=0;

​    }

  }

};


```

### **例题五：[289. 生命游戏](https://leetcode.cn/problems/game-of-life/)**

根据 [百度百科](https://baike.baidu.com/item/生命游戏/2926434?fr=aladdin) ， **生命游戏** ，简称为 **生命** ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 `m × n` 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： `1` 即为 **活细胞** （live），或 `0` 即为 **死细胞** （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 `m x n` 网格面板 `board` 的当前状态，返回下一个状态。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg)

```
输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg)

```
输入：board = [[1,1],[1,0]]
输出：[[1,1],[1,1]]
```

```c++

//一个很妙的的方法为了防止在改变一个数，影响了其他的值，可以考虑位运算，特别值的结果为01，因为他们只用到32位的最后一位，把新的值放到前一位，再>>右移即可。
class Solution {

public:

  void gameOfLife(vector<vector<int>>& board) {

​    int m=board.size(),n=board[0].size();

​    for(int i=0;i<m;i++){

​      for(int j=0;j<n;j++){

​        int live=0;

​        //查找该点周围细胞信息

​        for(int di=-1;di<=1;di++){

​          for(int dj=-1;dj<=1;dj++){

​            if((i+di)>=0&&(i+di)<m&&(j+dj)>=0&&(j+dj)<n&&!(di == 0 && dj == 0))

​              live+=board[di+i][dj+j]&1;

​          }

​        }

​        if(board[i][j]==1){

​          if(live<2||live>3)board[i][j]=1;

​          else board[i][j]=3;

​        }else{

​          if(live==3)board[i][j]=2;

​          else board[i][j]=0;

​        }           

​        

​      }

​    }

​     for(int i = 0;i<m;i++){

​      for(int j = 0;j<n;j++){

​        board[i][j] =(board[i][j]&2)>>1;//取每个网格的第二位，得到更新后状态

​      }

​    }

  }

};
```

## **数学**

### 知识点：



## 贪心算法

贪心算法主要分两类问题：区间问题和Huffman树解决问题：

### 首先区间问题：

以下问题是按照右端点排序

#### 例题1：[用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

步骤：

​	将每个区间按左端点从小到大排序

​	从前往后一次枚举每个区间

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 `points` ，其中`points[i] = [xstart, xend]` 表示水平直径在 `xstart` 和 `xend`之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 **完全垂直** 地射出。在坐标 `x` 处射出一支箭，若有一个气球的直径的开始和结束坐标为 `x``start`，`x``end`， 且满足  `xstart ≤ x ≤ x``end`，则该气球会被 **引爆** 。可以射出的弓箭的数量 **没有限制** 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 `points` ，*返回引爆所有气球所必须射出的 **最小** 弓箭数* 。

 

**示例 1：**

```
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
```

**示例 2：**

```
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。
```

**示例 3：**

```
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
```

 问题得本质是：整合区间，也就是区间最后由于交集可以最少整成多少个区间，也就是最少射箭数

```rust
做题笔记：区间选点模型
贪心选右端点
只有后一个区间的左端点大于前一个区间右端点，那么次数加一
```



```c++
class Solution {

public:

  int findMinArrowShots(vector<vector<int>>& points) {

​    int res=1;

​    sort(points.begin(),points.end(),[](vector<int> &a,vector<int>&b){//以右端点排序

​      return a[1]<b[1];

​    });

​    int x=points[0][1];

​    for(int i=1;i<points.size();i++){

​      //只有后一个区间的左端点大于前一个区间右端点，那么次数加一

​      if(points[i][0]>x){

​        res++;

​        x=points[i][1];

​      }



​    }

​    return res;



  }

};
```

#### 例题2：[无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

来源leetcode 435

给定一个区间的集合 `intervals` ，其中 `intervals[i] = [starti, endi]` 。返回 *需要移除区间的最小数量，使剩余区间互不重叠* 。

 

**示例 1:**

```
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
```

**示例 2:**

```
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
```

**示例 3:**

```
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
```

 

**提示:**

- `1 <= intervals.length <= 105`
- `intervals[i].length == 2`
- `-5 * 104 <= starti < endi <= 5 * 104`



```c++
//其实思路与例题1是一样的，统计无交集区间得个数
class Solution {

public:

  int eraseOverlapIntervals(vector<vector<int>>& points) {

​    int res=1;

​    sort(points.begin(),points.end(),[](vector<int> &a,vector<int>&b){

​      return a[1]<b[1];

​    });

​    int x=points[0][1];

​    for(int i=1;i<points.size();i++){

​      

​      if(points[i][0]>=x){

​        res++;

​        x=points[i][1];

​      }



​    }

​    return points.size()- res;

  }

};
```

以下问题是按照左端点排序

#### 例题3：[2406. 将区间分为最少组数](https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/)

给你一个二维整数数组 `intervals` ，其中 `intervals[i] = [lefti, righti]` 表示 **闭** 区间 `[lefti, righti]` 。

你需要将 `intervals` 划分为一个或者多个区间 **组** ，每个区间 **只** 属于一个组，且同一个组中任意两个区间 **不相交** 。

请你返回 **最少** 需要划分成多少个组。

如果两个区间覆盖的范围有重叠（即至少有一个公共数字），那么我们称这两个区间是 **相交** 的。比方说区间 `[1, 5]` 和 `[5, 8]` 相交。

 

**示例 1：**

```
输入：intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
输出：3
解释：我们可以将区间划分为如下的区间组：
- 第 1 组：[1, 5] ，[6, 8] 。
- 第 2 组：[2, 3] ，[5, 10] 。
- 第 3 组：[1, 10] 。
可以证明无法将区间划分为少于 3 个组。
```

**示例 2：**

```
输入：intervals = [[1,3],[5,6],[8,10],[11,13]]
输出：1
解释：所有区间互不相交，所以我们可以把它们全部放在一个组内。
```

 

**提示：**

- `1 <= intervals.length <= 105`
- `intervals[i].length == 2`
- `1 <= lefti <= righti <= 106`

![image-20231203215013380](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231203215013380.png)

```c++
class Solution {

public:

  int minGroups(vector<vector<int>>& a) {

​    sort(a.begin(),a.end());

​    priority_queue<int,vector<int>,greater<>>p;

​    for(auto &x:a){

​      if(!p.empty()&&p.top()<x[0])p.pop();

​      p.push(x[1]);

​    }

​    return p.size();

  }



};
```

#### 例题4：[删除被覆盖区间](https://leetcode.cn/problems/remove-covered-intervals/)来源leetcode1288

给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 `c <= a` 且 `b <= d` 时，我们才认为区间 `[a,b)` 被区间 `[c,d)` 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

**示例：**

```
输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
```

 

**提示：**

- `1 <= intervals.length <= 1000`
- `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
- 对于所有的 `i != j`：`intervals[i] != intervals[j]`

```c++
class Solution {

public:

  int removeCoveredIntervals(vector<vector<int>>& a) {

​    sort(a.begin(),a.end(),[](vector<int> &a,vector<int> &b){

​      if(a[0]!=b[0]) return a[0]<b[0];

​      return a[1]>b[1];});

​    int re=a.size(),r=0;//因为区间从大于等于0开始，利用这个使得可以让前后的右端点比较

​    for(auto &x:a){

​      if(x[1]<=r)re--;

​      r=max(r,x[1]);

​    }

​    return re;



  }

};


```

#### 例题5：[跳跃游戏](https://leetcode.cn/problems/jump-game/)

给你一个非负整数数组 `nums` ，你最初位于数组的 **第一个下标** 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

```
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

**示例 2：**

```leetcode
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
```

```c++
class Solution {

  //贪心

public:

  bool canJump(vector<int>& nums) {

   for(int i=0,j=0;i<nums.size();i++){

​     if(j<i) return false;

​     j=max(j,i+nums[i]);//局部最优体现贪心思想

   }

   return true;



  }

};
```

#### 例题5：[跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

给定一个长度为 `n` 的 **0 索引**整数数组 `nums`。初始位置为 `nums[0]`。

每个元素 `nums[i]` 表示从索引 `i` 向前跳转的最大长度。换句话说，如果你在 `nums[i]` 处，你可以跳转到任意 `nums[i + j]` 处:

- `0 <= j <= nums[i]` 
- `i + j < n`

返回到达 `nums[n - 1]` 的最小跳跃次数。生成的测试用例可以到达 `nums[n - 1]`。

 

**示例 1:**

```
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

**示例 2:**

```
输入: nums = [2,3,0,1,4]
输出: 2
```

```c++
class Solution {

public:

  int jump(vector<int>& nums) {

​    int max_step=0;

​    int count=0;

​    int end=0;

​    for(int i=0;i<nums.size()-1;i++){

​      max_step=max(max_step,i+nums[i]);//局部贪心最优

​      if(i==end){

​        end=max_step;

​        count++;

​      }     

​    }

​    return count;



  }

};
```



### Huffman树

#### 例题1：合并果子

经典哈夫曼树的模型，每次合并重量最小的两堆果子即可。使用小根堆维护所有果子，每次弹出堆顶的两堆果子，并将其合并，合并之后将两堆重量之和再次插入小根堆中。

```c++
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> heap;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        heap.push(x);
    }
    
    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    
    printf("%d\n", res);
    return 0;

}
```

## 动态规划

### **背包问题**

#### 01背包问题解释：

由多个背包，容量为V，N个物品重量（权重）为W，价值为v，从N个物品取，将物品总重量记为W，W要小于等于V，这些物品可以用记为1，不用则记为0，要求满足以上条件后最大价值是多少。特点：每件物品最多用一次

#### 问题分析思路：

![image-20231222192428722](C:\Users\16537\AppData\Roaming\Typora\typora-user-images\image-20231222192428722.png)

#### 例题1[416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-equal-subset-sumclass Solution {

```c++
public:

  bool canPartition(vector<int>& nums) {

​     //01背包

​    int n = nums.size();

​    int sum = 0;

​    for (auto x : nums) sum += x;

​    if (sum & 1) return false;//和为奇数，无解

​    int m = sum / 2;

​    vector<bool> f (m + 1, false);

​    f[0] = true;

​    for (auto x : nums){

​      for (int j = m ; j >= x ; j --){

​        f[j] = f[j] | f[j - x];

​      }

​    }

​    return f[m];

  }

};
```





#### 完全背包问题

和01差不多，就是物品次数可以重复使用

#### 多重背包问题

每个物品是有限的，而且有限制

#### 分组背包问题

### **线性DP**



### **区间DP**



### 计数DP
