// 3
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        std::cin >> arr[i]; 
    }
    
    std::sort(arr, arr+n);
    int res[n-1] = {arr[0]};
    int sum = arr[0];
    
    for (int i=1; i<n-1; i++) {
        res[i] = arr[i] + res[i-1];
        sum += res[i];
    }

    std::cout << sum;
}