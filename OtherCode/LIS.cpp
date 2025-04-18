// Longest Increasing Subsequnce
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> dp(n, 1);       // dp[i]: độ dài LIS mà kết thúc tại phần tử i
    vector<int> trace(n, -1);   // trace[i]: chỉ số phần tử trước đó trong LIS

    int maxLen = 1, lastIndex = 0;

    // Tính LIS
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }

        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // Truy vết dãy con LIS
    vector<int> lis;
    for (int i = lastIndex; i != -1; i = trace[i]) {
        lis.push_back(a[i]);
    }

    // Vì ta đi ngược, cần đảo lại
    reverse(lis.begin(), lis.end());

    // In kết quả
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}
