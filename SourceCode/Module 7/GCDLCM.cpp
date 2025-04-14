/* count the number of integers that satisfy the following conditions:
1. it shoud be a multiple of all a=elen=ments in the first array.
2. it should be a divisor of all elements in the second array. */

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> arr1; // size = m
std::vector<int> arr2; // size = n

void insertArr(int n, int arr[]) {
    for (int i=0; i<n; i++) {
        std::cin >> arr[i];
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); // Euclidean algorithm
}

// relation between GCD and LCM as is shown below
// --- GCD(a, b) * LCM(a, b) = a * b ---
int lcm(int a, int b) {
    return std::abs(a * b) / gcd(a, b);
}

// GCD of multiple numbers
int multigcd(std::vector<int> arr) {
    int result = arr[0];
    for (int i=1; i<(int)arr.size(); i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

// LCM of multiple numbers
int multilcm(std::vector<int> arr) {
    int result = arr[0];
    for (int i=1; i<(int)arr.size(); i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int m, n; 
    std::cin >> m >> n;
    arr1.resize(m);
    arr2.resize(n);

    insertArr(m, arr1.data());
    insertArr(n, arr2.data());
    
    int begin = multilcm(arr1);
    int end = multigcd(arr2);

    if (end % begin != 0) {
        std::cout << 0 << std::endl;
    } else {
        int count = 1;
        for (int i = 2; i<=end/begin; i++) {
            if (end % (begin * i) == 0) {
                count++;
            }
        }
        
        std::cout << count << std::endl;
    } 
    return 0;
}