//
// Created by 16537 on 2023/12/11.
//
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int x0=1,y0=1;
        for(int i=0;i<m;i++)
            if(!matrix[0][i])x0=0;
        for(int i=0;i<n;i++)
            if(!matrix[i][0])y0=0;

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(!matrix[i][0])
                for(int j=1;j<m;j++){
                    matrix[i][j]=0;
                }
        }

        for(int i=1;i<m;i++){
            if(!matrix[0][i])
                for(int j=1;j<n;j++){
                    matrix[j][i]=0;
                }
        }
        if(!x0){
            for(int i=0;i<m;i++)
                matrix[0][i]=0;
        }
        if(!y0){
            for(int j=0;j<n;j++)
                matrix[j][0]=0;
        }
    }
};