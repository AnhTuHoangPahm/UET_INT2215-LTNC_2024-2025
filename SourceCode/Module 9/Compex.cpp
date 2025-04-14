#include <iostream>
#include <cmath>

struct Complex { 
    double a, b; 

    void print(const Complex& c); 
    Complex add(const Complex& c1, const Complex &c2);
    int compare(const Complex& c1, const Complex &c2);
};
void print(const Complex& c) {
    if (c.b > 0 && c.b != 1) {
        std::cout << c.a << "+" << c.b << "i" << std::endl;
    } else if (c.b < 0 && c.b != -1) {
        std::cout << c.a << c.b << "i" << std::endl;
    } else if (c.b == -1 || c.b == 1) {
        if (c.a != 0) {
        std:: cout << c.a << (c.b > 0 ? "+i" : "-i") << std::endl;
        } else {
            std:: cout << (c.b > 0 ? "i" : "-i") << std::endl;
        }
    } else if (c.a == 0 || c.b == 0) {
        std:: cout << (c.a == 0 ? c.b : c.a) << std::endl;
    }
    // if (c.a == 0 && c.b == 0) 
}

Complex add(const Complex& c1, const Complex& c2) {
    Complex result;
    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
    return result;
}

int compare(const Complex& c1, const Complex& c2) {
    int result = 0;
    if (c1.a * c1.a + c1.b * c1.b < c2.a * c2.a + c2.b * c2.b) {
        result = -1; 
    } else if (c1.a * c1.a + c1.b * c1.b > c2.a * c2.a + c2.b * c2.b) {
        result = 1;
    }
    return result;
}

int main() {
    Complex c1 = {1, 3};
    Complex c2 = {2, 1};
    print(add(c1, c2));
    std::cout << compare(c1, c2);
}