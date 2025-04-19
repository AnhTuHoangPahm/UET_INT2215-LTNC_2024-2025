#include <iostream>
#include <string>
#include <iomanip>

// copy from here...
// fraction: a / b || -a / b
double evaluateFractionString(std::string fraction) {
    std::string a = "", b = "";

    int index = 0;
    while (fraction[index] != '/') {
        index++;
    }

    if (index == (int)fraction.length()) { // has no '/'
        throw "Bad fraction string.";
    }

    // extract
    for (int i=0; i<index; i++) {
        if ( (fraction[i] < '0'|| fraction[i] > '9') && fraction[0] != '-') {
            throw "Bad fraction string.";
            break;
        }
        a.push_back(fraction[i]);
    }
    for (int i=index+1; i<(int)fraction.length(); i++) {
        if (fraction[i] < '0' || fraction[i] > '9') {
            throw "Bad fraction string.";
            break;
        }
        b.push_back(fraction[i]);
    }

    if (a == "" || b == "") {
        throw "Bad fraction string.";
    }

    // stoi(string) automatically convert "-10" to -10,
    int numerator = std::stoi(a);
    int denominator = std::stoi(b);

    if (denominator == 0) {
        throw "Bad fraction string.";
    }

    return (double)numerator / denominator;
}
// ...up to this point 
// test if you want, maybe you can improve my programm :>
int main () {
    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        // fflush(stdin);
        try {
            double val = evaluateFractionString(line);
            std::cout << std::fixed << std::setprecision(2) << val << std::endl;
        } catch (const char* str){
            std::cout << "Caught " << str << std::endl;
        }
    }
}