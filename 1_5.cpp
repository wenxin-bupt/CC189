/*******************************************************************************
1.5 One Away

There are three types of edits that can be performed on strings: insert a
character, remove a character, or replace a character. Given two strings, write
a function to check if they are one edit (or zero edits) away.

EXAMPLE
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false
*******************************************************************************/

/*
C++ passes std::string by value. And here we only want to judge whether they are
one edit string. So we use const reference here.
*/

#include<iostream>
#include<string>

bool helper(std::string const&a, std::string const&b) {
    bool one_diff = false;
    int i=0, j=0;
    while (i<a.size() && j<b.size()) {
        if (a[i]!=b[j]) {
            if (one_diff) return false;
            one_diff = true;
            if (a.size()==b.size()) {
                i++;
            }
        } else {
            i++;
        }
        j++;
    }
    return true;
}

bool isOneAway(std::string const&a, std::string const&b) {
    if (a.size()==b.size()) {
        return helper(a, b);
    } else if (a.size()+1==b.size()) {
        return helper(a, b);
    } else if (b.size()+1==a.size()) {
        return helper(b, a);
    }
    return false;
}

int main() {
    std::string a = "pb";
    std::string b = "b";
    std::cout<<isOneAway(a, b);
    return 0;
}
