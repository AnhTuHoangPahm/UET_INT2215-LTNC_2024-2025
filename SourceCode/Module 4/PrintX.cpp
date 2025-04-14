#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    int rect_edge = 2*n + 1;
    
    for (int i=0; i<rect_edge; i++){
        for (int j=0; j<rect_edge; j++){
            if (i==j || i+j==rect_edge-1){
                cout << "* ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}