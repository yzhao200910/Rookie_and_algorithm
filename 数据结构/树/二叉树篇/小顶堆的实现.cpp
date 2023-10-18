//
// Created by 16537 on 2023/10/11.
//
#include <iostream>
#include <vector>

using namespace std;

class heap{
public:
    heap():size(0)
    {
        h.push_back(0);
    };
    void heap_swap(int a,int b){
        swap(ph[hp[a]],ph[hp[b]]);
        swap(hp[a],hp[b]);
        swap(h[a],h[b]);
    }
    void down(int t){//下沉操作
        int u=t;
        if(u*2<=h.size()&&h[t]>h[u*2]) t=u*2;
        if(u*2+1<=h.size()&&h[t]>h[u*2+1]) t=u*2+1;
        if(u!=t){
            heap_swap(h[u],h[t]);
            down(t);
        }
    }
    void up(int u){
        while(u/2 &&h[u/2]>h[u]){
            heap_swap(h[u/2],h[u]);
            u/=2;
        }
    }
    void insert(int k){//插入操作
        h.push_back(k);
        size++;
        up(size);

    }
    void delete_ITEM(int k){
       h[k]=h[size];
       size--;
       down(h[k]);

    }
    void change_item(int k,int x){
        h[k]=x;
        if(x==h[k]) return;
        if(x>h[k]) down(k);
        else up(k);
    }
private:
    vector<int> h;//储存的一维数组
    vector<int> ph;
    vector<int> hp;
    int size;
};