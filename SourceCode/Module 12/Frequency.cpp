#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

void frequency(std::map<char, int>& m, std::string s) {
    int len = s.length();
    for (int i=0; i<len; i++) {
        if (m.find(s[i]) == m.end()) {
            m.insert(std::pair<char, int> (s[i], 1));
        } else {
            m[s[i]]++;
        }
    }
}

int main() {
    std::map<char, int> m;
    std::string sample;

    std::string fileName;
    std::cin >> fileName;

    std::ifstream file(fileName);
    while (std::getline(file, sample)) {
        // string::erase(iterator __first, iterator __last)
        // std::remove(__first, __last, char). return an iterator-type
        sample.erase(std::remove(sample.begin(), sample.end(), '\r'), sample.end());
        frequency(m, sample);
    }

    for (std::map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " << it->second;
    }

    file.close();
} 