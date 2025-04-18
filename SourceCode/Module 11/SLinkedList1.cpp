// cho vào để editor không hiện lỗi
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node() {}
};
//
// copy từ đây trở đi
void print(Node* head)
{
    for (Node* p = head; p != NULL; p = p->next) {
        std::cout << p->value << " ";
    }
}

Node* insertHead(Node* head, int value)
{
    Node* nHead = new Node;
    nHead->value = value;
    nHead->next = head;
    head = nHead;
    return head;
}

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

Node* deleteNode(Node* head, int pos)
{
    int i = 0;
    Node* p = head;
    
    if (pos == 0) {
        p = p->next;
        head = p;
        return head;
    }
    
    while (i<pos-1) {
        p = p->next;
        i++;
    }
    p->next = p->next->next;
    return head;
}

int getValue(Node* head, int pos)
{
    int i = 0;
    Node* p = head;
    while (i<pos) {
        p = p->next;
        i++;
    }
    return p->value;
}