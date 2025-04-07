#include <iostream>
#include <string>
#include <vector>

std::string s;

void generate(std::string res, int n) {
    if (n == (int)res.length()) {
        std::cout << res << std::endl;
        return;
    }

    for (char c : s) {
        generate(res + c, n);
    }
}

int main() { 
    std::cin >> s;
   
    for (int i=1; i<=(int)s.length(); i++) {
        generate("", i);
    }
    
    return 0;
}