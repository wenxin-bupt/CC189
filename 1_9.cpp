/*******************************************************************************
1.9 String Rotation

Assume you have a method isSubString which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation
of s1 using only one call to isSubString (e.g.,"waterbottle" is a rotation of
"erbottlewat").
*******************************************************************************/

/***
被这道题bling到了！

如果用暴力的方法，只能找到所有的字符串的移位组合， 然后进行判断， 是~n^2级别
的算法。

如果用下面的思路：
original: "waterbottle"
rotated:  "erbottlewat"
我们把rotated加起来  "erbottlewat"+"erbottlewat" = "erbottlewaterbottlewat"
道理是yxyx中总有完整的xy

然后用 find() 就可以判断成功了。find() 函数根据stackoverflow也是逐一在暴力比较
并没有在使用KMP算法。 所以这里并没有算法复杂度的提升。

***/

#include<iostream>
#include<string>

bool isRotated(std::string &s1, std::string &s2) {
    if (s2.size()==s1.size()) {
        std::string t = s2+s2;
        return (int)(t.find(s1)) > -1;
    }
    return false;
}

int main() {
    std::string s1 = "waterbottle", s2 = "erbottlewat";
    std::cout<<isRotated(s1, s2);
    return 0;
}



