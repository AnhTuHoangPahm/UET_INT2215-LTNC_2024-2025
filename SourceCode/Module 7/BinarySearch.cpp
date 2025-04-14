#include <iostream>
using namespace std;

// begin solver
bool binSearch(int arr[], int n, int x) {
    int begin = 0;
    int end = n-1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (arr[mid] == x) {
            return true;
        } else if (arr[mid] < x) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    if (binSearch(arr, n, x)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}