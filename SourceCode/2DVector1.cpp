#include <iostream>
#include <iomanip>

class Vector {
    double x_, y_;
public:
    Vector(double x = 0, double y = 0);  
    void print(int precision = 2, bool newLine = true); 
    void truncate(double length);
    bool isOrtho(const Vector& v) const;
    static float dot(const Vector& v1, const Vector& v2);
    static float cross(const Vector& v1, const Vector& v2);
    friend std::ostream& operator<< (std::ostream& os, const Vector& v);
};

Vector::Vector(double x, double y) : x_(x), y_(y) {}

void Vector::print(int precision, bool newLine) {
    std::cout << std::fixed << std::setprecision(precision) << "(" << this->x_ << "," << this->y_ << ")";
    if (newLine) {
        std::cout << std::endl;
    }
}

void Vector::truncate(double length) {
    this->x_ -= length;
    this->y_ -= length;
}

bool Vector::isOrtho(const Vector& v) const {
    return (dot(*this, v) == 0 ? true : false);
}

float Vector::dot(const Vector& v1, const Vector& v2) {
    return v1.x_ * v2.x_ + v1.y_ * v2.y_;
}

float Vector::cross(const Vector& v1, const Vector& v2) {
    return v1.x_ * v2.y_ - v1.y_ * v2.x_;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << std::fixed << std::setprecision(2) << "("<< v.x_ << "," << v.y_ << ")";
    return os;
}

int main() {
    Vector vec(2.0, 3.0);
    Vector vec1(3.0, 2.0);
    // vec.print();
    // vec.truncate(2);
    std::cout << vec1.isOrtho(vec) << std::endl;
    std::cout << Vector::dot(vec, vec1);
    // std::cout << ;
}