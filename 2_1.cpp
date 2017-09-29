/*******************************************************************************
2.1 Remove Dups

Write code to remove duplicates from an unsorted linked list.

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?
*******************************************************************************/

#include<iostream>
#include<list>
#include<set>

/*
list 的知识点
1. list 的iterator是循环遍历的， 即一个iterator如果取到了end， *p返回的是list中的
   最后一个元素。 ++p则回到begin(). 所以如果循环超过数组边界，最后一个元素会出现
   两次。
2. 如果list为空， 则iterator => end(), begin()都可以取值，而且返回值为默认值。对于
   int则为0.
3. emplace_back 含有构造功能，即直接将构造参数传给这个函数就好。push_back则只是
   复制元素。
*/


// In place
struct {
    void removeDups(std::list<int> &l) {
        for (std::list<int>::iterator p = l.begin(); p != l.end(); p++) {
            std::list<int>::iterator q  = p;
            q++;
            while (q!=l.end()){
                if (*q == *p)
                    q = l.erase(q);
                else
                    q++;
            }
        }

    }
} ver1;

// With buffer
struct {
    void removeDups(std::list<int> &l) {
        std::set<int> m;
        for (std::list<int>::iterator p = l.begin(); p != l.end();) {
            if (m.count(*p)==0) {
                m.insert(*p);
                p++;
            } else {
                p = l.erase(p);
            }
        }
    }
} ver2;



int main() {
    int t[] = {1,2,3,4,5,6,7,3,2,1,5};
    std::list<int> l(t, t+sizeof(t)/sizeof(int));
    for (int i : l) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    ver2.removeDups(l);
    for (int i : l) {
        std::cout<<i<<" ";
    }
    std::list<int> ll;
    return 0;
}





