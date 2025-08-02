#include <iostream>
#include <vector>
using namespace std;

// 8 hướng xung quanh
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main() {
    int m, n;
    cout << "Insert row, col: ";
    cin >> m >> n;  // m hàng, n cột

    cout << "Inset the matrix: " << '\n';
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    // Vector để lưu các toạ độ thoả mãn điều kiện
    vector<pair<int, int>> cucDai;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isMax = true;

            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (a[i][j] < a[ni][nj]) {
                        isMax = false;
                        break;
                    }
                }
            }

            if (isMax) {
                cucDai.push_back({i, j});
            }
        }
    }

    cout << '\n' << "Result(S): ";

    for (auto p : cucDai) {
        int i = p.first, j = p.second;
        cout << a[i][j] << " ";
    }

    return 0;
}
