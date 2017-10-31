/*******************************************************************************
2.4 Partition

Write code to partition a linked list around a value x, such that all nodes less
than x come before all nodes greater than or equal to x. If x is contained
within the list the values of x only need to be after the elements less than
x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right
partitions.

EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*******************************************************************************/
#include<vector>
#include<iostream>
#include<list>
/*
思路:
因为是链表，所以能采用的方案有很多。 这里我还是用了类似于数组的方案。 
还有的想法是
1. 新开一个链表，存储小于val值的，然后merge这两个链表。 这种方法保证了稳定
2. 新开一个链表，*head， *tail， 首尾都有指针，然后小于val的从head添加， 大于val的从
   tail添加。 也可，但是这里会打乱链表中原有的顺序。
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

void partitionBasedOnValue(LinkedNode* head, int x) {
    if (head == NULL) return;
    LinkedNode *first = head, *second;
    while (first) {
        while (first && first->val<x) {
            first=first->next;
        }
        second = first;
        while (second && second->val>=x) {
            second=second->next;
        }
        if (second==NULL) break;
        std::swap(first->val, second->val);
        first=first->next;
    }
}


int main() {
    std::vector<int> vec = {1,7,2,5,6,2,1,3,4,2,1,4,6,7,8,5,9,2,7,3,6,3};
    LinkedNode* head = geneLinkedList(vec);
    printLinkedList(head);
    partitionBasedOnValue(head, 5);
    printLinkedList(head);
    return 0;
}





