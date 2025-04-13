// wq   ->    ww www wwq wq wqw wqq qw qww qwq qq qqw qqq
// depth-first.
#include <iostream>
#include <string>
#include <vector>

// Biến toàn cục để lưu xâu gốc, giúp hàm đệ quy dễ truy cập
std::string original_input;

// Hàm đệ quy để tạo các xâu
// current_string: xâu đang được xây dựng trong lần gọi đệ quy này
void generate(std::string current_string) {
    int len = current_string.length();

    // --- Điều kiện dừng và In kết quả ---
    // Nếu xâu hiện tại có độ dài 2, in nó ra
    if (len == 2) {
        std::cout << current_string << " ";
    }
    // Nếu xâu hiện tại có độ dài 3, in nó ra
    if (len == 3) {
        std::cout << current_string << " ";
    }

    // --- Bước đệ quy ---
    // Nếu độ dài hiện tại nhỏ hơn độ dài tối đa mong muốn (là 3),
    // thì tiếp tục gọi đệ quy để xây dựng xâu dài hơn.
    if (len < 3) {
        // Lặp qua từng ký tự trong xâu gốc
        for (char c : original_input) {
            // Gọi lại hàm generate với xâu hiện tại được nối thêm ký tự 'c'
            generate(current_string + c);
        }
    }
    // Nếu len >= 3, không cần gọi đệ quy nữa, hàm sẽ tự kết thúc (quay lui)
}

int main() {
    std::cout << "Nhập vào xâu ký tự: ";
    std::cin >> original_input;

    // Xử lý trường hợp xâu rỗng
    if (original_input.empty()) {
        std::cout << "Xâu nhập vào rỗng, không thể tạo xâu con." << std::endl;
        return 0;
    }

    std::cout << "Output: ";
    // Bắt đầu quá trình đệ quy với một xâu rỗng ""
    generate("");
    std::cout << std::endl; // In dòng mới kết thúc output

    return 0;
}