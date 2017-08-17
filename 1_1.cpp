#include<iostream>
#include<string>
#include<set>

using namespace std;

// Considering the input string's charset is very important here.

/***
When we can assume that the charset is ASSII.
Use a set or char array
***/
struct {
    bool uniqueCharacters(string s) {
        set<char> mem;
        for (char c : s) {
            if (mem.count(c)==0)
                mem.insert(c);
            else
                return false;
        }
        return true;
    }
} ver1;

/***
When we can assume all the characters are all lower cases.
Bitmask is a smart solution
***/
struct {
    bool uniqueCharacters(string s) {
        int bitmask = 0;
        for (char c : s) {
            if (bitmask&(1<<int(c)))
                return false;
            else
                bitmask |= (1<<int(c));
        }
        return true;
    }
} ver2;

int main() {
    string t = "abc";
    cout<<ver1.uniqueCharacters(t)<<endl;
    cout<<ver2.uniqueCharacters(t)<<endl;
    return 0;
}





