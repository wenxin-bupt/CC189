/*******************************************************************************
2.3 Delete Middle Node

Implement an algorithm to delete a node in the middle (i.e., any node but the
first and last node, not necessarily the exact middle) of a singly linked list,
given only access to that node.

EXAMPLE
Input:the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
*******************************************************************************/
#include<vector>
#include<iostream>
#include<list>

/*
思路:
限制条件 given only access to that node 只能访问被指定删除的结点
这里返回值为bool是比较好的设计， false失败， true成功。

删除指针 delete(ptr)
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

bool deleteNodeInMiddle(LinkedNode* node) {
    if (node == NULL || node->next == NULL) return false;
    node->val = node->next->val;
    LinkedNode* temp = node->next;
    node->next = node->next->next;
    delete(temp);
    return true;
}


int main() {
    std::vector<int> vec = {1,2,3,4,5,6,7};
    LinkedNode* head = geneLinkedList(vec);
    printLinkedList(head);
    LinkedNode* test = head->next->next->next;
    deleteNodeInMiddle(test);
    printLinkedList(head);
    return 0;
}





