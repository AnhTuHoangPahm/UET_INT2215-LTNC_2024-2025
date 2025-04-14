#include <iostream>
#include <vector>

int N;

int path[10];

void print(int path[]) {
    for (int i=0; i<N; i++) {
        std::cout << path[i];
    }
    std::cout << std::endl;
}

void binCombine(int i) {
    for (int j=0; j<=1; j++) {
        path[i] = j;
        if (i+1 == N) {
            print(path);
        } else {
            binCombine(i+1);
        }
    }
}

int main() {
    std::cin >> N;
    binCombine(0);
}