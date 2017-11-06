/*******************************************************************************
2.5 Sum Lists

You have two numbers represented by a linked list,where each node contains a
single digit. The digits are stored in reverse order,such that the 1's digit is
at the head of the list. Write a function that adds the two numbers and returns
the sum as a linked list.

EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9.That is,912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2.That is, 912
*******************************************************************************/
#include<vector>
#include<iostream>
#include<list>
#include<climits>
/*
INT_MAX, INT_MIN的使用直接引入<climits>即可。
NULL的使用不需要引入文件

1. 这道题的本意还是大数相加， 重写在addList()里面
2. reverseList竟然之前做题的时候没有实现过，这里也实现一下备用。
3. 指针声明了一定要赋值。
*/

struct LinkedNode {
   int val;
   LinkedNode *next;
   LinkedNode(int x = 0) : val(x), next(NULL) {}
};

LinkedNode* geneLinkedList(std::vector<int> &vec) {
   LinkedNode *head=NULL, *node=NULL;
   for (int i=0; i<vec.size(); i++) {
        if (i == 0) {
            head = new LinkedNode(vec[i]);
            node = head;
        } else {
            node->next = new LinkedNode(vec[i]);
            node = node->next;
        }
   }
   return head;
}

void printLinkedList(LinkedNode *node) {
    while (node != NULL) {
        std::cout<<node->val<<" ";
        node = node->next;
    }
    std::cout<<std::endl;
}

int geneNumberReverse(LinkedNode *head) {
    long long res = 0, w = 1;
    LinkedNode *p = head;
    while (p) {
        res += w*p->val;
        if (res > INT_MAX) {
            return -1;
        }
        w *= 10;
        p = p->next;
    }
    return res;
}

int geneNumber(LinkedNode *head) {
    long long res = 0, w = 1;
    LinkedNode *p = head;
    while (p) {
        res = w*res + p->val;
        if (res > INT_MAX) {
            return -1;
        }
        w *= 10;
        p = p->next;
    }
    return res;
}

int sumLists(LinkedNode *a, LinkedNode *b) {
    long long res_a = geneNumberReverse(a);
    long long res_b = geneNumberReverse(b);
    if (res_a==-1 || res_b==-1 || res_a + res_b > INT_MAX)
        return -1;
    else
        return res_a+res_b;
}

LinkedNode* reverseList(LinkedNode* head) {
    LinkedNode *pre=NULL, *cur=head, *pos=NULL;
    while (cur!=NULL) {
        pos = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pos;
    }
    return pre;
}

LinkedNode* addLists(LinkedNode *a, LinkedNode *b) {
   LinkedNode *head=NULL, *ptr=NULL;
   int carry = 0;
   while (a!=NULL && b !=NULL) {
        if (head==NULL) {
            head = new LinkedNode((a->val+b->val+carry)%10);
            ptr = head;
        } else {
            ptr->next = new LinkedNode((a->val+b->val+carry)%10);
            ptr = ptr->next;
        }
        carry = (a->val+b->val+carry)/10;
        a = a->next;
        b = b->next;
   }
   LinkedNode *p = NULL;
   a!=NULL ? p=a : p=b;
   while (p!=NULL) {
        if (head==NULL) {
            head = new LinkedNode((p->val+carry)%10);
            ptr = head;
        } else {
            ptr->next = new LinkedNode((p->val+carry)%10);
            ptr = ptr->next;
        }
        carry = (p->val+carry)/10;
        p = p->next;
   }
   if (carry==1) {
        ptr->next = new LinkedNode(1);
   }
   return head;
}



int main() {
    std::vector<int> vec1 = {9,91,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
    std::vector<int> vec2 = {};
    printLinkedList(reverseList(geneLinkedList(vec2)));
    return 0;
}






