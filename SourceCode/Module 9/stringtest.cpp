#include <iostream>

int main() {
    const char* str = "hello";
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    std::cout << len;
}