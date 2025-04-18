// cho vào để editor không hiện lỗi
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node() {}
};
//
// copy từ đây
bool compareLists(Node* headA, Node* headB) {
    if (headA == nullptr && headB == nullptr) {
        return false;
    }
    
    if (headA == nullptr || headB == nullptr) {
        return false;
    }
    
    Node* p1 = headA;
    Node* p2 = headB;

    while (p1 != NULL && p2 != NULL) {
        if (p1->value != p2->value || (p2->next == NULL && p1->next != NULL) || (p1->next == NULL && p2->next != NULL)) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}