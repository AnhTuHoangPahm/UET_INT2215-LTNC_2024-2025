#include <iostream>
#include <cmath>

struct Point {
    double x, y;  // Toạ độ x, y
    Point(); // Hàm khởi tạo điểm (0, 0)
    Point(double, double); // Hàm khởi tạo từ toạ độ x, y
    Point(const Point& p); // Hàm khởi tạo sao chép từ một thực thể (instance) Point khác
};

Point::Point() : x(0), y(0) {}

Point::Point(double x_, double y_) : x(x_), y(y_) {}

Point::Point(const Point& p) {
    *this = p;
}

double Distance(Point p1_, Point p2_) {
    return sqrt(pow(p1_.x - p2_.x, 2) + pow(p1_.y - p2_.y, 2));
}


class Triangle {
    Point p1, p2, p3;
public:
    Triangle(Point, Point, Point); // Hàm khởi tạo tam giác từ 3 điểm
    double getPerimeter() const;  // Hàm trả về chu vi tam giác
    double getArea() const;  // Hàm trả về diện tích tam giác
};

Triangle::Triangle(Point p1_, Point p2_, Point p3_) {
    p1 = p1_;
    p2 = p2_;
    p3 = p3_;
}

double Triangle::getPerimeter() const {
    return (Distance(p1, p2) + Distance(p2, p3) + Distance(p3, p1));
}

double Triangle::getArea() const {
    return abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;
}

int main() {
    Point A(1,1), B(1, 4), C(5, 1);
    std::cout << A.x << " " << A.y << std::endl;
    std::cout << B.x << " " << B.y << std::endl;
    std::cout << C.x << " " << C.y << std::endl;
    Triangle tri(A, B, C);

    std::cout << tri.getPerimeter() << std::endl;
    std::cout << tri.getArea() << std::endl;
}


