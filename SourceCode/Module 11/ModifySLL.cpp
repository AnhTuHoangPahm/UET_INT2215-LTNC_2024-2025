// cho vào để editor không hiện lỗi
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node() {}
};
// copy từ đây
// super hard-code 
Node* insertHead(Node* head, int value)
{
    Node* nHead = new Node;
    nHead->value = value;
    nHead->next = head;
    head = nHead;
    return head;
}

Node* deleteDuplicates(Node* head)
{
    for (Node* p = head; p != NULL; ) {
        if (p->next == NULL) break;

        while (p->value == p->next->value) {
            p->next = p->next->next;
            if (p->value == p->next->value && p->next->next == NULL) {
                p->next = NULL;
                return head;
            }
        }   
        p = p->next;
    }
    return head;
}
//      it ->11-> p  
//  00->00->      00->00
Node* insert(Node* head, int value)
{
    // it đi đến Node cuối cùng mà có giá trị < value
    Node* it = head;
    // ở hần tử đầu tiên 
    if (it->value > value) {
        head = insertHead(head, value);
        return head;
    }
    
    while (it->next != NULL && it->next->value < value) {
        it = it->next;
        // đến phần tử cuối rồi
        if (it->next == NULL) {
            Node* nNode = new Node;
            nNode->value = value;
            it->next = nNode;
            nNode->next = NULL;
            return head;
        }
    }

    for (Node* p = head; p != NULL; p = p->next) {
        if (p->value >= value) {
            Node* nNode = new Node;
            nNode->value = value;
            it->next = nNode;
            nNode->next = p;
            break;
        }
    }
    return head;
}