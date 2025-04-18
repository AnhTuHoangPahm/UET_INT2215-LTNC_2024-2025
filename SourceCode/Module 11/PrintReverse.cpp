// cho vào để editor không hiện lỗi
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node() {}
};
// pre-defined 
void print(Node* head)
{
    for (Node* p = head; p != NULL; p = p->next) {
        std::cout << p->value << " ";
    }
}

// copy từ đây
void printReverse(Node* head)
{
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        // gán next := Node liền sau current Node
        next = current->next;
        // đảo lại pointer của Node 
        current->next = prev;
        // Tiến các con trỏ thêm 1 vị trí
        prev = current;
        current = next;
    }
    head = prev; // biến Node cuối ds thành Node đầu.

    print(head); // pre-defined
}