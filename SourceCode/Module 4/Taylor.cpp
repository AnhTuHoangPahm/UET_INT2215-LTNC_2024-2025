#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double fact(int a) {
    if (a==0 || a==1){
        return 1;
    }
    else {
        return a * fact(a-1);
    }
}

int main() {
    int n; cin >> n;
    int i=1;
    double sum = 1, old_sum = 0;

    // dynamic programming
    while (sum - old_sum > 0.001) {
        old_sum = sum;
        sum += pow(n, i) / fact(i);
        i++;
    }
    
    cout << fixed << setprecision(4) <<sum;
}