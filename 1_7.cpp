/*******************************************************************************
1.7 Rotate Matrix

Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*******************************************************************************/
/*
C++ 数组尤其是多维数组还是很难用的。
多维数组在程序传参中几乎没有实际使用价值， 因为它不允许更改多维数组的大小。
*/
#include<iostream>

void rotateFourPoints(int* mat, int i, int j, int N) {
    int pos[4][2] = {{i, j}};
    if (N%2) {
        int c = N/2;
        pos[1][0] = c+(j-c);
        pos[1][1] = c-(i-c);
        pos[2][0] = c-(i-c);
        pos[2][1] = c-(j-c);
        pos[3][0] = c-(j-c);
        pos[3][1] = c+(i-c);
    } else {
        int c = N-1;
        i *= 2; j*= 2;
        pos[1][0] = (c+(j-c))/2;
        pos[1][1] = (c-(i-c))/2;
        pos[2][0] = (c-(i-c))/2;
        pos[2][1] = (c-(j-c))/2;
        pos[3][0] = (c-(j-c))/2;
        pos[3][1] = (c+(i-c))/2;
    }
    int temp = *(mat+pos[3][0]*N+pos[3][1]);
    for (int i=3; i>0; i--) {
        *(mat+pos[i][0]*N+pos[i][1]) = *(mat+pos[i-1][0]*N+pos[i-1][1]);
    }
    *(mat+pos[0][0]*N+pos[0][1]) = temp;
}

void rotateMatrix(int *mat, int N) {
    int l = N/2;
    for (int i=0; i<l; i++)
        for (int j=0; j<l; j++)
            rotateFourPoints(mat, i, j, N);
    if (N%2) {
        for (int i=0; i<N/2; i++)
            rotateFourPoints(mat, i, N/2, N);
    }
}

void printMatrix(int *mat, int N) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            std::cout<<*(mat+i*N+j)<<" ";
        }
        std::cout<<std::endl;
    }
}

int main() {
    int mat[9] = {1,2,3,4,5,6,7,8,9};
    printMatrix(mat, 3);
    rotateMatrix(mat, 3);
    printMatrix(mat, 3);
}



