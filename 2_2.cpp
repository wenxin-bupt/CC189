/*******************************************************************************
2.2 Return Kth to Last

Implement an algorithm to find the kth to last element of a singly linked list.
*******************************************************************************/
#include<vector>
#include<iostream>
#include<list>

/*
思路: two pointers

知识点:
1. NULL 并不在std命名空间中，直接使用即可
2. 记得用初始化列表 LinkedNode(int x = 0) : val(x), next(NULL) {}
*/

struct LinkedNode {
   int val;
   LinkedNode *next;
   LinkedNode(int x = 0) : val(x), next(NULL) {}
};

LinkedNode* geneLinkedList(std::vector<int> &vec) {
   LinkedNode *head, *node;
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

LinkedNode* getLastKth(LinkedNode* head, int k) {
    LinkedNode *p1 = head, *p2 = head;
    for (int i=0; i<k; i++) {
        if (p1==NULL) break;
        p1 = p1->next;
    }
    while (p1 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}


int main() {
    std::vector<int> vec = {1,2,3,4,5,6,7};
    LinkedNode* head = geneLinkedList(vec);
    printLinkedList(head);
    printLinkedList(getLastKth(head, 0));
    return 0;
}





