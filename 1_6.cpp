/*******************************************************************************
1.6 String Compression

Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become a2blc5a3.

If the "compressed" string would not become smaller than the original string,
your method should return the original string. You can assume the string has
only uppercase and lowercase letters (a - z)
*******************************************************************************/

/*
1. std::to_string() is included in <string>
2. Operations like str1+str2 will take great amount of time. Because for a "+"
   function, it creates a buffer and return a new std::string each time it is
   called. To eliminate this time cost, we can use += or append(). These two
   function know where to put the result, so they don't create new buffers.
   And the most efficient way is when you know the final length of the new
   std::string, you can first use a reserve() at the original std::string to
   pre-allocate the space.
3. std::string.append(num, char)
   std::string.append(std::string)
*/

#include<iostream>
#include<string>

std::string compress(std::string& s) {
    std::string cs;
    int i=0;
    while (i<s.size()) {
        cs.append(1, s[i]);
        int cnt=0, j=i;
        while (j<s.size()&&s[j]==s[i]) {
            cnt++;
            j++;
        }
        cs.append(std::to_string(cnt));
        i=j;
    }
    return cs.size()<s.size()?cs:s;
}

int main() {
    std::string s = "aabcccccaaa";
    std::cout<<compress(s);
    return 0;
}
