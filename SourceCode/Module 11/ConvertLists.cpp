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
Node* convert(Node* head)
{
    Node* it = head;
    while (it != NULL) {
        Node* tracker = it; // tracker đến Node liền trước pSlow, bắt đầu cùng với Node iterator
        Node *pSlow = it, *pFast = it;
        while (pFast != NULL) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        // di chuyển tracker
        while (tracker->next != pSlow) {
            tracker = tracker->next;
        }

        // next của tracker sẽ trỏ đến Node sau pSlow
        tracker->next = pSlow->next;
        // pSlow->next sẽ trỏ tới node liền sau it(erator)
        pSlow->next = it->next;
        // sau đó it->next sẽ trỏ tới node pSlow
        it->next = pSlow;
        it = it->next->next; // ignore 2 Nodes
    }
    return head;
}

/*
list has even number of elements

*/
/* 1 3 5 2 4 6
a1->b1->a2 => ignore 2 first nodes
1 2 | 3 5 4 6
a2->b2->a3 => ignore next 2 nodes 
1 2 | 3 4 | 5 6
iterate->next = nullptr => return */