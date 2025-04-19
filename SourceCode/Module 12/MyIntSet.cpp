#include <iostream>
#include <vector>
#include <algorithm>
// copy from here...
class MyIntSet{
public:
    MyIntSet():num(0) {}

    MyIntSet(int a[], int n){
        if(n > MAX_SIZE) num = MAX_SIZE;
        else num = n;
        for(int i = 0; i < num; i++) elements[i] = a[i];
    }

    bool insertVal(int v);
    bool eraseVal(int v);
    void clearAll();
    bool findVal(int v) const;
    bool isEmpty() const;
    int getSize() const;
    const int* getBeginPtr() const;
    const int* getEndPtr() const;
private:
    static const int MAX_SIZE = 1000;
    int elements[MAX_SIZE];
    int num; // count real values in this set
};

bool MyIntSet::insertVal(int v) {
    if (num == MAX_SIZE) {
        return false;
    }
    // note that this set contains distinc elements
    int* p = std::find(elements, elements + num, v);
    if (p != elements + num) { // found once
        return false;
    } else {
        elements[num] = v;
        num++;
        return true;
    }
    
}

bool MyIntSet::eraseVal(int v) {
    if (isEmpty()) {
        return false;
    }

    int* p = std::find(elements, elements + num, v);
    if (p == elements + num) { // not found
        return false;
    } else {
        // iterate to near-last element in array.
        for (int* current = p; current < elements + num - 1; current++) {
            *current = *(current + 1);
        }
        num--;
    }

    return true;
}

void MyIntSet::clearAll() {
    num = 0;
}

bool MyIntSet::findVal(int v) const {
    const int* p = std::find(elements, elements + num, v);
    if (p != elements + num) { // found once
        delete p;
        return true;
    }
    return false;
}

bool MyIntSet::isEmpty() const {
    return num == 0;
}

int MyIntSet::getSize() const {
    return num;
}

const int* MyIntSet::getBeginPtr() const {
    return elements;
}

const int* MyIntSet::getEndPtr() const {
    return elements + num - 1;
}
// ...up to this point
int main () {    
    MyIntSet is1;
    // is1.eraseVal(6);
    is1.insertVal(3);
    is1.insertVal(3);
    is1.insertVal(5);
    // std::cout << is1.num << std::endl;
    std::vector<int> res;
    for(auto p = is1.getBeginPtr(); p <= is1.getEndPtr(); p++){
        res.push_back(*p);
    }
    // std::cout << res.size() << std::endl;
    std::sort(res.begin(), res.end());
    for(int i = res.size() - 1; i >= 0; i--) {
        std::cout << res[i] << " ";
    }
}
