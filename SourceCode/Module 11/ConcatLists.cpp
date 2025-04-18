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
Node* concat(std::vector<Node*> heads) {
    int size = heads.size();
    bool isNull[size] = {false};
    for (int i=0; i<size; i++) {
        if (heads[i] == nullptr) {
            isNull[i] = true;
        }
    }
    
    Node* tempHead;
    int index = 0;
    for (int i=0; i<size; i++) {
        if ( !(isNull[i]) ) {
            tempHead = heads[i];
            index = i;
            break;
        } 
    }

    for (Node* p = heads[index]; p != NULL; p = p->next) {
        if (p->next == NULL) {
            for (int j=index + 1; j<size; j++) {
                if ( !(isNull[j]) ) {
                    p->next = heads[j];
                    index = j;
                    break;
                }
            }
        }
    }

    return tempHead;
}