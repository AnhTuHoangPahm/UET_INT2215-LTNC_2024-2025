#include <iostream>
#include <string>
#include <vector>

int M, N;

void print(std::vector<std::string> path) {
    for (int i=0; i<(int)path.size(); i++) {
        std::cout << path[i] << std::endl;
    }
}

void binCombine(int m, int n, std::string a, std::vector<std::string>& path) {
    if (m == 0 && n==0) {
        path.push_back(a);
        return;
    }
    
    if (m > 0) {
        binCombine(m-1, n, a + '0', path);
    }
    
    if (n > 0) {
        binCombine(m, n-1, a + '1', path);
    }
}

int main() {
    std::cin >> M >> N;
    std::vector<std::string> path;
    binCombine(M, N, "", path);
    
    print(path);
}