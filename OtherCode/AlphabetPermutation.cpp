#include <iostream>
#include <vector>
#include <string>
using namespace std;

void per(int k, string word, vector<char>& s, vector<bool>& used) {
    if ((int)word.size() == k) {
        cout << word << endl;
        return;
    }

    for (int i=0; i<(int)s.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            per(k, word + s[i], s, used);
            used[i] = false;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<char> letters;
    for (int i=0; i<n; i++) {
        letters.push_back('a' + i);
    }

    vector<bool> used(n, false);
    per(k, "", letters, used);

    return 0;
}