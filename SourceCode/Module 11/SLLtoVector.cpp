// cho vào để editor không hiện lỗi
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* next;

    Node() {}
};
//
// copy từ đây
std::vector<int> linkedListToVector(Node* head)
{
    std::vector<int> values;
    for (Node* p = head; p != NULL; p = p->next) {
        values.push_back(p->value);
    }
    return values; 
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

Node* vectorToLinkedList(std::vector<int> values)
{
    Node* head = nullptr;
    
    for (int i=0; i<(int)values.size(); i++) {
        head = insertTail(head, values[i]);
    }
    return head; 
}