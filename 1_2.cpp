#include <algorithm>    // std::swap

using namespace std;

/***
In C, a char takes 4 bytes
In C++, a char take 1 byte

C++ is passing array by reference. Be careful.
***/

void reverseCStyleString(char cl[]) {
    if (sizeof(cl)<3) return;
    int len = (sizeof(cl)/sizeof(*cl));
    int i=0, j=len-2;
    while (i<j) {
        swap(cl[i++], cl[j--]);
    }
}

int main() {
    char t[4] = {'a', 'b', 'c', '\0'};
    reverseCStyleString(t);
    return 0;
}
