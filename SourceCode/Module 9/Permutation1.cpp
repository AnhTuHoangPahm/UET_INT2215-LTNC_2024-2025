#include <iostream>
std::string res = "";

void per(bool check[], std::string s, int index) {
    for (int i=0; i<(int)s.length(); i++) {
        if (!check[i]) {
            check[i] = true;
            res += s[i];
            if ((int)res.length() == (int)s.length()) {
                std::cout << res << std::endl;
            } else {
                per(check, s, index + 1);
            }
            check[i] = false;
            res.pop_back(); // remove last character 
        }
    }
    
}

int main() {
    std::string s;
    std::cin >> s;
    bool check[(int)s.length()] = {false};

    per(check, s, 0);

    return 0;
}