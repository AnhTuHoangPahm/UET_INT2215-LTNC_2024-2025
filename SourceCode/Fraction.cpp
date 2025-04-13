#include <iostream>

class MyFraction {
private:
    int a, b;
public:
    MyFraction(int _a = 1, int _b = 1);
    void print() const;
    MyFraction add(const MyFraction& f) const;
    MyFraction substract(const MyFraction& f) const;
    MyFraction multiply(const MyFraction& f) const;
    MyFraction divide(const MyFraction& f) const;
    void simplify();
    int compare(const MyFraction& f) const;
};

MyFraction::MyFraction(int _a, int _b) : a(_a), b(_b) {
    simplify();
}

void MyFraction::print() const {
    if (this->b != 0) {
        std::cout << this->a << "/" << this->b << std::endl;
    } else {
        std::cout << "invalid";
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); // Euclidean algorithm
}

void MyFraction::simplify() {
    int res = gcd(this->a, this->b);
    this->a /= res;
    this->b /= res;
}

MyFraction MyFraction::add(const MyFraction& f) const {
    int temp_a = this->a * f.b + this->b * f.a;
    int temp_b = this->b * f.b;
    MyFraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

MyFraction MyFraction::substract(const MyFraction& f) const {
    int temp_a = this->a * f.b - this->b * f.a;
    int temp_b = this->b * f.b;
    MyFraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

MyFraction MyFraction::multiply(const MyFraction& f) const {
    int temp_a = this->a * f.a;
    int temp_b = this->b * f.b;
    MyFraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

MyFraction MyFraction::divide(const MyFraction& f) const {
    if (f.a == 0) {
        std::cerr << "Error: Cannot divide by zero fraction." << std::endl;
        return *this; // Hoặc xử lý lỗi khác tùy bạn
    } 

    int temp_a = this->a * f.b;
    int temp_b = this->b * f.a;
    MyFraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

int MyFraction::compare(const MyFraction& f) const {
    bool result = this->a * f.b == this->b * f.a ? true : false;
    if(result) {
        return 0;
    } else {
        if (this->a * f.b > this->b * f.a) {
            return 1;
        } else {
            return -1;
        }
    }
}

int main() {
    MyFraction x, y(1, 3);
    std::cout << "x: "; x.print();
    x.add(y).print();
    x.substract(y).print();
    x.multiply(y).print();
    x.divide(y).print();
    std:: cout << x.compare(y) << std::endl;
}