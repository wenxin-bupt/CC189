/*******************************************************************************
1.4 Check Permutation

Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same frwards and backwards.
A permutation is a rearrangement of letters. The palindrome does not need to be
limited to just dictionary words.

EXAMPLE
Input:  Tact Coa
Output: True (permutations: "taco cat", "atco eta", etc.)
*******************************************************************************/

/*
与下面给出解法无关的一个trick

要检查某个数组排列中是否只有一个比特位是1
考虑 00010000:
00010000 - 1 = 00001111
00010000 & 00001111 = 0

所以写为代码就是: (mask & (mask - 1)) == 0
*/

#include <iostream>
#include <string>
#include <cctype>
#include <map>

bool IsPalindromePermutation(std::string str) {
    std::map<char, int> mem;
    for (char c : str) {
        if (c!=' ') mem[tolower(c)]++;
    }
    bool odd = false;
    for (auto p : mem) {
        if (p.second%2) {
            if (!odd) odd = true;
            else return false;
        }
    }
    return true;
}

int main() {
    std::string str = "Tact Coa";
    std::cout<<IsPalindromePermutation(str)<<std::endl;
    return 0;
}
