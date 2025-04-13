/*
Cho phép tạo thời gian từ ba tham số nguyên giờ, phút, giây
Cho phép tạo thời gian từ hai tham số nguyên giờ, phút
Cho phép tạo thời gian từ một tham số nguyên giờ
Có thể dùng lệnh cout
    để in ra màn hình theo định dạng hh:mm:ss
    (ví dụ 08:20:10)
Các biến kiểu Time
    có thể so sánh với nhau (lớn hơn, nhỏ hơn, bằng, khác, lớn hơn hoặc bằng, nhỏ hơn hoặc bằng)
Có hàm thành viên int hour() trả về giờ hiện tại
Có hàm thành viên int minute() trả về phút hiện tại
Có hàm thành viên int second() trả về giây hiện tại
*/

#include <iostream>
#include <iomanip>
#include <string>

class Time {
private:
    int hr, min, sec;

public:
    Time (int hour) : hr(hour), min(0), sec(0) {
        convert();
    }
    Time (int hour, int minute) : hr(hour), min(minute), sec(0) {
        convert();
    }
    Time (int hour, int minute, int second) : hr(hour), min(minute), sec(second) {
        convert();
    }

    Time convert();
    friend std::ostream& operator<< (std::ostream& os, const Time& t);
    bool operator>(const Time& t) const;
    bool operator<(const Time& t) const;
    bool operator==(const Time& t) const;
    bool operator!=(const Time& t) const;
    bool operator>=(const Time& t) const;
    bool operator<=(const Time& t) const;

    int hour();
    int minute();
    int second();
};

int Time::hour() {
    return hr;
}

int Time::minute() {
    return min;
}

int Time::second() {
    return sec;
}

Time Time::convert() {
    int toSecond = this->hr * 3600 + this->min *  60 + this->sec;
    this->hr = toSecond / 3600;
    toSecond %= 3600;
    this->min = toSecond / 60;
    this->sec = toSecond %= 60;
    return *this;
}

std::ostream& operator<< (std::ostream& os, const Time& t) {
    os << std::setw(2) << std::setfill('0') << t.hr << ":"
       << std::setw(2) << std::setfill('0') << t.min << ":" 
       << std::setw(2) << std::setfill('0') << t.sec << std::endl;
    return os;
}

bool Time::operator>(const Time& t) const {
    return (this->hr * 3600 + this->min *  60 + this->sec > t.hr * 3600 + t.min * 60 + t.sec);
}

bool Time::operator<(const Time& t) const {
    return (this->hr * 3600 + this->min *  60 + this->sec < t.hr * 3600 + t.min * 60 + t.sec);
}

bool Time::operator==(const Time& t) const {
    return (this->hr * 3600 + this->min *  60 + this->sec == t.hr * 3600 + t.min * 60 + t.sec);
}

bool Time::operator>=(const Time& t) const {
    return operator>(t) || operator==(t);
}

bool Time::operator<=(const Time& t) const {
    return operator<(t) || operator==(t);
}

bool Time::operator!=(const Time& t) const {
    return !(operator==(t));
}

int main() {
    Time t1(12, 3, 6), t2(11, 5, 30);
    std::cout << Time(2, 70, 80);
    std::cout << std::boolalpha << (t1 >= t2) << std::endl;
    std::cout << t1.hour() << std::endl;
}









