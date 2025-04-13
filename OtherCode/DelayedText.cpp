#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// Function to print text with a delay between each character
void printWithDelay(const std::string& text, int delayMilliseconds) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush(); // Important: Flush the output buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
    std::cout << std::endl; // Add a newline at the end
}

// Function to print text with a delay between each word
void printWordsWithDelay(const std::string& text, int delayMilliseconds) {
    std::string currentWord;
    for (char c : text) {
        if (c == ' ' || c == '\0') { // Word boundary or end of string
            if (!currentWord.empty()) { // Avoid printing empty words
                std::cout << currentWord << " ";
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
                currentWord.clear();
            }
        } else {
            currentWord += c;
        }
    }
    if (!currentWord.empty()) { // Print the last word
        std::cout << currentWord;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
    std::cout << std::endl;
}



int main() {
    std::string message1 = "Hello, this is a message printed with a character delay.";
    std::string message2 = "This is another message, printed with a word delay.";

    std::cout << "Printing message 1 with character delay:" << std::endl;
    printWithDelay(message1, 50); // 50 milliseconds delay per character

    std::cout << "\nPrinting message 2 with word delay:" << std::endl;
    printWordsWithDelay(message2, 200); // 200 milliseconds delay per word

    return 0;
}