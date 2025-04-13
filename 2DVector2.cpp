#include <iostream>
#include <iomanip>

class Vector {
    double x_, y_;
public:
Vector(double x = 0, double y = 0);  
void print(int precision = 2, bool newLine = true); 
Vector operator+(double s) const;    
Vector operator-(double s) const;
Vector operator*(double s) const;
Vector operator/(double s) const;
Vector& operator+=(double s);    
Vector& operator-=(double s);
Vector& operator*=(double s);
Vector& operator/=(double s);
};

Vector::Vector(double x, double y) : x_(x), y_(y) {}

void Vector::print(int precision, bool newLine) {
    std::cout << std::fixed << std::setprecision(precision) << "(" << this->x_ << ", " << this->y_ << ")";
    if (newLine) {
        std::cout << std::endl;
    }
}

Vector Vector::operator+(double s) const {
    Vector res(0, 0);
    res.x_ = this->x_ + s;
    res.y_ = this->y_ + s;
    return res;
}

Vector Vector::operator-(double s) const {
    Vector res(0, 0);
    res.x_ = this->x_ - s;
    res.y_ = this->y_ - s;
    return res;
} 

Vector Vector::operator*(double s) const {
    Vector res(0, 0);
    res.x_ = this->x_ * s;
    res.y_ = this->y_ * s;
    return res;
} 

Vector Vector::operator/(double s) const {
    Vector res(0, 0);
    res.x_ = this->x_ / s;
    res.y_ = this->y_ / s;
    return res;
} 

Vector& Vector::operator+=(double s) {
    this->x_ += s;
    this->y_ += s;
    return *this;
}

Vector& Vector::operator-=(double s) {
    this->x_ -= s;
    this->y_ -= s;
    return *this;
}

Vector& Vector::operator*=(double s) {
    this->x_ *= s;
    this->y_ *= s;
    return *this;
}

Vector& Vector::operator/=(double s) {
    this->x_ /= s;
    this->y_ /= s;
    return *this;
}

int main() {
    Vector vec(6, 6);
    Vector vec1(1, 1);
    Vector vec2(1, 2);
    Vector r;
    r = vec - 1;
    r.print();
}