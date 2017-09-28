/*******************************************************************************
1.8 Zero Matrix

Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0
*******************************************************************************/

// 这道题要考虑如何用O(1)的空间占用去解决问题， 容易想到用边缘的两条去存储为0的
// 情况。 但是，置0的时候就会面临一个问题。 对边置0的时候，如果把别的边置0了就。
// 影响了全局。所以第一轮要从下标1开始。

// 用了assign方法

#include<iostream>
#include<vector>


void printMatrix(std::vector<std::vector<int>>& mat) {
    int m = mat.size(), n = 0;
    if (m) n = mat[0].size();
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            std::cout<<mat[i][j];
        }
        std::cout<<std::endl;
    }
}

void zeroMatrix(std::vector<std::vector<int>>& mat) {
    int m = mat.size(), n = 0;
    if (m) n = mat[0].size();
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (mat[i][j]==0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
    for (int i=1; i<m; i++) {
        if (mat[i][0] == 0) {
            mat[i].assign(n, 0);
        }
    }
    for (int j=0; j<n; j++) {
        if (mat[0][j] == 0) {
            for (int i=0; i<m; i++) {
                mat[i][j] = 0;
            }
        }
    }
    if (m>0 && n>0 && mat[0][0]==0)
        mat[0].assign(n, 0);
    return;
}


int main() {
    std::vector<std::vector<int>> test = {{0, 1, 0}, {3, 4, 5}, {6, 7, 8}};
    printMatrix(test);
    zeroMatrix(test);
    printMatrix(test);
}



