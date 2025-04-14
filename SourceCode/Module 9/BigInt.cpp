#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class BigInt {
    std::string value;
    int sign;
public:
    // Hàm khởi tạo số nguyên lớn
    BigInt();
    BigInt(const char*);
    BigInt(int );
    BigInt(const BigInt& );

    // Toán tử in ra màn hình
    friend std::ostream& operator<< (std::ostream& , const BigInt& );

    // Toán tử gán
    BigInt& operator=(int );
    BigInt& operator=(const char*);
    BigInt& operator=(const BigInt& );

    // Toán tử cộng
    friend BigInt operator+(const BigInt& , const BigInt & );
    friend BigInt operator+(const BigInt& , int );
    friend BigInt operator+(int , const BigInt &);

    // Toán tử trừ
    friend BigInt operator-(const BigInt& , const BigInt & );
    friend BigInt operator-(const BigInt& , int );
    friend BigInt operator-(int , const BigInt &);

    // Toán tử cộng rồi gán
    BigInt& operator+=(int );
    BigInt& operator+=(const BigInt& );

    // Toán tử trừ rồi gán
    BigInt& operator-=(int );
    BigInt& operator-=(const BigInt& );
};

// Toán tử in ra màn hình
std::ostream& operator<<(std::ostream& os, const BigInt& num)
{
    os << (num.sign == 1 ? "" : "-") << num.value;
    return os;
}

// Hàm khởi tạo
BigInt::BigInt() : value("0"), sign(1) {}

BigInt::BigInt(const char* num)
{
    if (num[0] == '-') {
        value = std::string(num).substr(1); // lấy tất cả trừ dấu âm
        sign = -1;
    } else {
        value = std::string(num);
        sign = 1;
    }
}

BigInt::BigInt(int num)
{
    sign = (num < 0 ? -1 : 1);
    value = sign == 1 ? std::to_string(num) : std::to_string(num).substr(1);
}

BigInt::BigInt(const BigInt& num)
{
    value = num.value;
    sign = num.sign;
}

// Toán tử gán
BigInt& BigInt::operator=(int num)
{
    this->sign = (num < 0 ? -1 : 1);
    this->value = this->sign == 1 ? std::to_string(num) : std::to_string(num).substr(1);
    return *this;
}

BigInt& BigInt::operator=(const BigInt& num)
{
    // check tự gán
    if (this == &num) {
        return *this;
    }

    this->value = num.value;
    this->sign = num.sign;
    return *this;
}

BigInt& BigInt::operator=(const char *num)
{
    if (num[0] == '-') {
        this->sign = -1;
        this->value = std::string(num).substr(1);
    }  else {
        this->sign = 1;
        this->value = std::string(num);
    }
    return *this;
}

std::string add(const std::string& s1, const std::string& s2) {
    std::string result;
    int sum = 0, carry = 0;
    int i = s1.length() - 1, j = s2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        sum = carry + (i >=0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtract(const std::string& s1, const std::string& s2) {
    std::string result;
    int diff = 0, borrow = 0;
    int i = s1.length() - 1, j = s2.length() - 1;

    while (i >= 0 || j >= 0) {
        diff = (i >=0 ? s1[i--] - '0' : 0) - (j >= 0 ? s2[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    while(result.length() > 1 && result.back() == '0') result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

// ouput| >= : 1 | < : 0
bool compare(const std::string& a, const std::string& b) {
    // Chuẩn hóa chuỗi (bỏ số 0 dư thừa ở đầu)
    std::string normalizedA = a;
    std::string normalizedB = b;

    while (normalizedA.length() > 1 && normalizedA[0] == '0') {
        normalizedA.erase(0, 1);
    }
    while (normalizedB.length() > 1 && normalizedB[0] == '0') {
        normalizedB.erase(0, 1);
    }

    // So sánh độ dài || ss chuỗi
    if (normalizedA.length() != normalizedB.length()) {
        return normalizedA.length() > normalizedB.length();
    } else {
        return (normalizedA >= normalizedB);
    }
}

// Toán tử cộng
BigInt operator+(const BigInt& num, const BigInt& other)
{
    BigInt result;
    if (num.sign == other.sign) {
        result.sign = num.sign;
        result.value = (result.sign == 1 ? "" : "-") + add(num.value, other.value);
    } else {
        if (compare(num.value, other.value)) {
            if (num.value == other.value) {
                return result;
            }
            result.sign = num.sign;
            result.value = /*(result.sign == 1 ? "" : "-") + */ subtract(num.value, other.value);
        } else {
            result.sign = other.sign;
            result.value = /*(result.sign == 1 ? "" : "-") + */subtract(other.value, num.value);
        }
    }
    return result;
}

BigInt operator+(const BigInt& num, int other)
{
    BigInt another;
    another.sign = (other > 0 ? 1 : -1);
    another.value = std::to_string(other);
    return (num + another);
}

BigInt operator+(int num, const BigInt& other)
{
    return (other + num);
}

// Toán tử trừ
BigInt operator-(const BigInt& num, const BigInt& other)
{
    BigInt result;
    if (num.sign != other.sign) {
        result.sign = num.sign;
        result.value = /*(result.sign == 1 ? "" : "-") + */ add(num.value, other.value);
    } else {
        if (compare(num.value, other.value)) { 
            if (num.value == other.value) {
                return result;
            }

            result.sign = num.sign;
            result.value = /*(result.sign == 1 ? "" : "-") + */ subtract(num.value, other.value);
        } else {
            result.sign = - other.sign;
            result.value = /*(result.sign == 1 ? "" : "-") + */ subtract(other.value, num.value);
        }
    }
    return result;
}

BigInt operator-(const BigInt& num, int other)
{
    BigInt another;
    another.sign = (other > 0 ? 1 : -1);
    another.value = std::to_string(other);
    return (num - another);
}

BigInt operator-(int num, const BigInt& other)
{
    BigInt another;
    another.sign = (num > 0 ? 1 : -1);
    another.value = std::to_string(num);
    return (another - other);
}

// Toán tử cộng rồi gán
BigInt& BigInt::operator+=(int num)
{
    BigInt temp(num);
    if (this->sign == temp.sign) {
        this->value = add(this->value, temp.value);
    } else {
        if (compare(this->value, temp.value)) {
            if (this->value == temp.value) {
                this->value = "0";
                this->sign = 1;
            } else {
                this->value = subtract(this->value, temp.value);
            }
        } else {
            this->value = subtract(temp.value, this->value);
            this->sign = temp.sign;
        }
    }
    return *this;
}

BigInt& BigInt::operator+=(const BigInt& num)
{
    if (this->sign == num.sign) {
        this->value = add(this->value, num.value);
    } else {
        if (compare(this->value, num.value)) {
            if (this->value == num.value) {
                this->value = "0";
                this->sign = 1;
            } else {
                this->value = subtract(this->value, num.value);
            }
        } else {
            this->value = subtract(num.value, this->value);
            this->sign = num.sign;
        }
    }
    return *this;
}

// Toán tử trừ rồi gán
BigInt& BigInt::operator-=(int num)
{
    BigInt temp(num);
    if (this->sign != temp.sign) {
        this->value = add(this->value, temp.value);
    } else {
        if (compare(this->value, temp.value)) { 
            if (this->value == temp.value) {
                this->value = "0";
                this->sign = 1;
            }

            this->value = subtract(this->value, temp.value);
        } else {
            this->sign = - temp.sign;
            this->value = subtract(temp.value, this->value);
        }
    }
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& num)
{
    if (this->sign != num.sign) {
        this->value = add(this->value, num.value);
    } else {
        if (compare(this->value, num.value)) { 
            if (this->value == num.value) {
                this->value = "0";
                this->sign = 1;
            }

            this->value = subtract(this->value, num.value);
        } else {
            this->sign = - num.sign;
            this->value = /* (this->sign == 1 ? "" : "-") + */ subtract(num.value, this->value);
        }
    }
    return *this;
}

int main() {
    BigInt a1 = "-10", b1 = "20", c1 = 5;
    std::cout << (a1 + b1) << std::endl;
    std::cout << (b1 + a1) << std::endl;
    std::cout << (b1 + c1) << std::endl;
    std::cout << (a1 - b1) << std::endl; // --30
    std::cout << (b1 - a1) << std::endl;
    std::cout << (b1 - c1) << std::endl;
    
    BigInt e = -10;
    e -= BigInt("4");
    std::cout << e << std::endl; // --14

    BigInt f;
    f = -100;
    std::cout << f << std::endl; // -100

    BigInt num;
    std::cout << num << std::endl; 
    // 0
    BigInt num1("4879124129988949491929991249124912312");
    std::cout << num1 << std::endl;
    // 4879124129988949491929991249124912312
    std::cout << BigInt(123) << std::endl;
    // 123
    BigInt num2 = 40;
    std::cout << num2 << std::endl;
    // 40
    BigInt num3 = "4441";
    std::cout << num3 << std::endl;
    // 4441
    BigInt tmp(23);
    BigInt num4(tmp);
    std::cout << num4 << std::endl;
    // 23
    BigInt a = BigInt("7412391231723192399991239");
    BigInt b = BigInt(21348123);
    std::cout << a + b << std::endl;
    std::cout << 43 + a << std::endl;
    std::cout << b + 71 << std::endl;
    // 7412391231723192421339362
    // 7412391231723192399991282
    // 21348194
    BigInt num5("34123");
    num5 += 23;
    num5 += BigInt("3341");
    std::cout << num5 << std::endl;
    // 37487
}