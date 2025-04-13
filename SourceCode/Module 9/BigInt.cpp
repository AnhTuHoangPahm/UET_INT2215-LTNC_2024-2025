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

    return os;
}

// Hàm khởi tạo
BigInt::BigInt() 
{
    
}

BigInt::BigInt(const char* num)
{
    if (num[0] != '-') {
        value = std::string(num).substr(1); // lấy tất cả trừ dấu âmâm
        sign = -1;
    } else {
        value = std::string(num);
        sign = 1;
    }
}

BigInt::BigInt(int num)
{
    
}

BigInt::BigInt(const BigInt& )
{
    
}

// Toán tử gán
BigInt& BigInt::operator=(int num)
{
    return *this;
}

BigInt& BigInt::operator=(const BigInt& num)
{
    return *this;
}

BigInt& BigInt::operator=(const char *num)
{
    return *this;
}

std::string add(std::string& s1, std::string& s2) {
    std::string result;
    int sum = 0, carry = 0;
    int i = s1.length() - 1, j = s2.length() - 1;

    while (i >= 0 || j >= 0 || carry >= 0) {
        sum += carry + (i >=0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0);
        result.push_back(sum % 10 + '0');
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtract(std::string& s1, std::string& s2) {
    std::string result;
    int diff = 0, borrow = 0;
    int i = s1.length() - 1, j = s2.length() - 1;

    while (i >= 0 || j >= 0 || borrow >= 0) {
        diff += - borrow + (i >=0 ? s1[i--] - '0' : 0) - (j >= 0 ? s2[j--] - '0' : 0);
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

// ouput| == : 0 | > : 1 | < : -1
int compare(const std::string& a, const std::string& b) {
    // Chuẩn hóa chuỗi (bỏ số 0 dư thừa ở đầu)
    std::string normalizedA = a;
    std::string normalizedB = b;

    while (normalizedA.length() > 1 && normalizedA[0] == '0') {
        normalizedA.erase(0, 1);
    }
    while (normalizedB.length() > 1 && normalizedB[0] == '0') {
        normalizedB.erase(0, 1);
    }

    // So sánh độ dài
    if (normalizedA.length() != normalizedB.length()) {
        return (normalizedA.length() < normalizedB.length() ? -1 : 1);
    }

    if (normalizedA == normalizedB) {
        return 0;
    } else {
        if (normalizedA < normalizedB) {
            return -1;
        } else {return 1;}
    }
}

// Toán tử cộng
BigInt operator+(const BigInt& num, const BigInt& other)
{
    if (num.sign == other.sign) {
        return BigInt((num.sign == 1 ? "" : "-") + add(num.value, other.value)) // see string to char* in Edge
    }
    return BigInt(); 
}

BigInt operator+(const BigInt& num, int other)
{
    return BigInt(); // Sua dong nay
}

BigInt operator+(int num, const BigInt& other)
{
    return BigInt(); // Sua dong nay
}

// Toán tử trừ
BigInt operator-(const BigInt& num, const BigInt& other)
{
    return BigInt(); // Sua dong nay
}

BigInt operator-(const BigInt& num, int other)
{
    return BigInt(); // Sua dong nay
}

BigInt operator-(int num, const BigInt& other)
{
    return BigInt(); // Sua dong nay
}

// Toán tử cộng rồi gán
BigInt& BigInt::operator+=(int num)
{
    return *this;
}

BigInt& BigInt::operator+=(const BigInt& num)
{
    return *this;
}

// Toán tử trừ rồi gán
BigInt& BigInt::operator-=(int num)
{
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& num)
{
    return *this;
}