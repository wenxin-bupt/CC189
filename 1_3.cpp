/*******************************************************************************
1.3 URLify

Write a method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end to hold the additional characters,
and that you are given the "true" length of the string. (Note: If implementing
in Java, please use a character array so that you can perform this operation in
place.)

EXAMPLE
Input:  "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"
*******************************************************************************/
#include<iostream>

/*
1. char[] can't be declared as a return type.
2. sizeof 是全局函数(关键字)，并不是std空间中的.
3. sizeof a a是一个数组
   对数组的操作， sizeof在声明的作用域执行的时候返回的是数组的元素数目。 如果这里的a
   是传入的形参， 那么a实际上是一个指针，所以返回的是指针的byte长度。而且莫名会花很
   多时间(mingw32-g++)， 后证明是杀软检测.
*/

void URLifyCharArray (char arr[], int sz) {
    int new_sz = 0;
    for (int i=0; i<sz; i++) {
        new_sz++;
        if (arr[i]==' ') new_sz+=2;
    }
    for (int i=new_sz-1, j=sz-1; j>=0; j--) {
        if (arr[j]==' ') {
            arr[i--] = '0';
            arr[i--] = '2';
            arr[i--] = '%';
        } else
            arr[i--] = arr[j];
    }
    return;
}

int main() {
    char arr[] = "123      ";
    URLifyCharArray(arr, 4);
    std::cout<<arr;
    return 0;
}
