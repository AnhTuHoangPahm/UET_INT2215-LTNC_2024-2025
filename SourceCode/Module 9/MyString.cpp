#include <iostream>

class MyString {
    char* str;
    int len;
public:
    // Hàm khởi tạo xâu rỗng
    MyString();
    // Hàm khởi tạo từ một xâu kiểu c-string
    MyString(const char* );
    // Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
    MyString(const MyString& );
    // Hàm huỷ
    ~MyString();
    // Toán tử gán
    MyString operator=(const MyString& );
    MyString operator=(const char* );
    // Toán tử nối xâu rồi gán
    MyString operator+=(const MyString& );
    // Toán tử truy cập đến từng kí tự
    char& operator[] (unsigned int index);
    const char& operator[] (unsigned int index) const;
    // Hàm trả về độ dài của xâu
    int size();
    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
    MyString upper() const;
    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
    MyString lower() const;
    // Toán tử để in ra màn hình
    friend std::ostream& operator<< (std::ostream& , const MyString& );
    // Toán tử nối xâu
    friend MyString operator+ (const MyString& , const MyString& );
    // Các toán tử so sánh
    friend bool operator< (const MyString& , const MyString& );
    friend bool operator> (const MyString& , const MyString& );
    friend bool operator<=(const MyString& , const MyString& );
    friend bool operator>=(const MyString& , const MyString& );
    friend bool operator==(const MyString& , const MyString& );
    friend bool operator!=(const MyString& , const MyString& );
};

// Toán tử truy cập đến từng kí tự
char& MyString::operator[] (unsigned int index) {
    if (index >= (unsigned int)len) {
        return str[-1];
    } else {
        return str[index];
    }
    
}
const char& MyString::operator[] (unsigned int index) const {
    if (index >= (unsigned int)len) {
        return str[-1];
    } else {
        return str[index];
    }
}

// Hàm khởi tạo xâu rỗng
MyString::MyString() : str(nullptr), len(0) {}

// Hàm khởi tạo từ một xâu kiểu c-string
MyString::MyString(const char* s) {
    len = 0;
    while(s[len] != '\0') {
        len++;
    }

    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
}

// Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
MyString::MyString(const MyString& s) {
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
}

// Hàm huỷ
MyString::~MyString() {
    delete[] str;
}

// Toán tử gán
MyString MyString::operator=(const MyString& s) {
    if (this == &s) {return *this;}
    delete[] str;

    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
    return *this;
}

MyString MyString::operator=(const char* s) {
    if (str == s) {return *this;}
    delete[] str;

    len = 0;
    while(s[len] != '\0') {
        len++;
    }

    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
    return *this;
}

// Toán tử nối xâu rồi gán
MyString MyString::operator+=(const MyString& s) {
    int newLen = len + s.len;
    char* newStr = new char[newLen + 1];
    for (int i = 0; i < len; i++) {
        newStr[i] = str[i];
    }
    
    for (int j = 0; j < newLen; j++) {
        newStr[len + j] = s[j];
    }
    newStr[newLen] = '\0';

    delete[] str;
    str = newStr;
    len = newLen;
    return *this;
}

// Hàm trả về độ dài của xâu (khi Khởi tạo đã tính len)
int MyString::size() {
    return len;
}

// Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
MyString MyString::upper() const {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    return *this;
}

// Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
MyString MyString::lower() const {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return *this;
}

// Toán tử để in ra màn hình
std::ostream& operator<< (std::ostream& os, const MyString& s) {
    if (s.str) {
        os << s.str;
    }
    return os;
}

// Toán tử nối xâu
MyString operator+ (const MyString& s1, const MyString& s2) {
    MyString result;

    result.len = s1.len + s2.len;
    result.str = new char[result.len + 1];

    for (int i = 0; i < s1.len; i++) {
        result[i] = s1[i];
    }

    for (int j = 0; j < s2.len; j++) {
        result[s1.len + j] = s2[j];
    }
    result.str[result.len] = '\0';

    return result;
}

// Các toán tử so sánh
bool operator< (const MyString& s1, const MyString& s2) {
    for (int i = 0; i < (s1.len <= s2.len ? s1.len : s2.len); i++) {
        if (s1[i] < s2[i]) {return true;}
        if (s1[i] > s2[i]) {return false;}
    }
    return s1.len < s2.len;
}
bool operator> (const MyString& s1, const MyString& s2) {
    return !(s1 < s2);
}
bool operator==(const MyString& s1, const MyString& s2) {
    if (s1.len != s2.len) {return false;}
    for (int i = 0; i < s1.len; i++) {
        if (s1[i] != s2[i]) {return false;}
    }
    return true;
}
bool operator<=(const MyString& s1, const MyString& s2) {
    return (s1 < s2 || s1 == s2);
}
bool operator>=(const MyString& s1, const MyString& s2) {
    return (s1 > s2 || s1 == s2);
}

bool operator!=(const MyString& s1, const MyString& s2) {
    return !(s1 == s2);
}

int main () {
    // add: delete used MyString
    std::cout << MyString() << std::endl;
    std::cout << MyString("test") << std::endl; // test
    MyString s1("abc");
    std::cout << MyString(s1) << std::endl; // abc
    MyString s2 = "test";
    std::cout << s2 << std::endl; // test
    MyString s3("test");
    MyString s4 = s3;
    std::cout << s4 << std::endl; // test
    MyString s5("abc");
    s5 += "def";
    std::cout << s5 << std::endl; // abcdef
    MyString s6("abcdef");
    std::cout << s6[0] << s6[3] << std::endl; // ad
    const MyString s7("abcdef");
    std::cout << s7[0] << s7[3] << std::endl; // ad
    std::cout << MyString("abcd").size() << std::endl; // 4
    std::cout << MyString("AbCd").upper() << std::endl; // ABCD
    std::cout << MyString("AbCd").lower() << std::endl; // abcd
    MyString s8 = "abc", s9 = "def";
    MyString s10 = s8 + s9;
    std::cout << s10 << std::endl; // abcdef
    std::cout << (MyString("abc") < MyString("abd")) << std::endl; // 1
    std::cout << (MyString("abc") <= MyString("abd")) << std::endl; // 1
    std::cout << (MyString("abc") > MyString("abd")) << std::endl; // 0
    std::cout << (MyString("abc") >= MyString("abd")) << std::endl; // 0
    std::cout << (MyString("abc") == MyString("abd")) << std::endl; // 0
    std::cout << (MyString("abc") != MyString("abd")) << std::endl; // 1
}