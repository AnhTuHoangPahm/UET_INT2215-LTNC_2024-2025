// lozenge or diamond?

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    
    for (int i=-n; i<=n; i++){
        for (int j=-n; j<=n; j++){
            if (abs(i)+abs(j) <= n){
                cout << "* ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}