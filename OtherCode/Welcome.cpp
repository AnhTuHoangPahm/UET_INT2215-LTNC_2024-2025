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

void readArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        std::cin >> arr[i];
    }
}

int main(){
    std::string message1 = "Booting";
    std::string message2 = "...";
    std::string message3 = "Integrating System Units";
    std::string message4 = "Checking Memory";
    std::string message5 = "Welcome, User!";

    printWithDelay(message1, 60);  printWithDelay(message2, 150); 
    printWithDelay(message3, 60);  printWithDelay(message2, 150); 
    printWithDelay(message4, 60);  printWithDelay(message2, 150); 
    printWithDelay(message5, 35); 
}