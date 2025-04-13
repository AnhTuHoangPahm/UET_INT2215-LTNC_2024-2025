#include <iostream>

class Fraction {
    int a, b;
public:
    Fraction(int a = 1, int b = 1);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    void simplify();
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
};

Fraction::Fraction(int _a, int _b) : a(_a), b(_b) {
    simplify();
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    if (f.b == 0) {
        os << "invalid";
    } else {
        os << f.a << '/' << f.b;
    }
    return os;
}

// Euclidean algorithm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); 
}

void Fraction::simplify() {
    int res = gcd(this->a, this->b);
    this->a /= res;
    this->b /= res;
}

Fraction Fraction::operator+(const Fraction& f) const {
    int temp_a = this->a * f.b + this->b * f.a;
    int temp_b = this->b * f.b;
    Fraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

Fraction Fraction::operator-(const Fraction& f) const {
    int temp_a = this->a * f.b - this->b * f.a;
    int temp_b = this->b * f.b;
    Fraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

Fraction Fraction::operator*(const Fraction& f) const {
    int temp_a = this->a * f.a;
    int temp_b = this->b * f.b;
    Fraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

Fraction Fraction::operator/(const Fraction& f) const {
    int temp_a = this->a * f.b;
    int temp_b = this->b * f.a;
    Fraction temp(temp_a, temp_b);
    temp.simplify(); 
    return temp;
}

bool Fraction::operator>(const Fraction& f) const {
    bool result = this->a * f.b > this->b * f.a ? true : false;
    return result;
}

bool Fraction::operator<(const Fraction& f) const {
    bool result = this->a * f.b < this->b * f.a ? true : false;
    return result;
}





