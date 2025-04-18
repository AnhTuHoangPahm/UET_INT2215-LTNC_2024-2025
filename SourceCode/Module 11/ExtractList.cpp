// cho vào để editor không hiện lỗi
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node() {}
};
//
// copy từ đây 
// not optimized solution
Node* insertTail(Node* head, int value)
{
    if (head == nullptr) {
        Node* nHead = new Node;
        nHead->value = value;
        nHead->next = NULL;
        head = nHead;
        return head;
    }
    
    for (Node* p = head; p!= NULL; p = p->next) {
        if (p!= NULL && p->next == NULL) {
            Node* nTail = new Node;
            nTail->value = value;
            nTail->next = NULL;
            p->next = nTail;
            break;
        }
    }
    return head;
}

Node* extractNodes(Node* head, int threshold) {
    Node* nList = nullptr;
    
    for (Node* p = head; p!= NULL; p = p->next) {
        if (p->value < threshold) {
            nList = insertTail(nList, p->value);
        }
    }
    return nList; 
}
