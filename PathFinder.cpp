#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> maze;  // Mê cung
vector<vector<int>> path;  // Đường đi

// Độ dịch chuyển theo 4 hướng: phải, xuống, trái, lên
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool findPath(int x, int y) {
    // Nếu đã đến góc phải dưới, đánh dấu và trả về true
    if (x == n - 1 && y == m - 1) {
        path[x][y] = 2;
        return true;
    }

    // Đánh dấu ô hiện tại là đường đi
    path[x][y] = 2;

    // Duyệt 4 hướng: phải, xuống, trái, lên
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Kiểm tra ô mới có hợp lệ không
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && path[nx][ny] != 2) {
            if (findPath(nx, ny))  // Đệ quy tìm đường từ ô mới
                return true;
        }
    }

    // Nếu không tìm được đường, quay lui
    path[x][y] = 0;
    return false;
}

int main() {
    cin >> n >> m;
    maze.resize(n, vector<int>(m));
    path.resize(n, vector<int>(m, 0));

    // Nhập mê cung
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 1) {
                path[i][j] = 1;  // Đánh dấu ô tường
            }
        }
    }

    // Bắt đầu tìm đường từ góc trái trên
    if (findPath(0, 0)) {
        // In ra mê cung với đường đi được đánh số 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Không có đường đi từ góc trái trên đến góc phải dưới." << endl;
    }

    return 0;
}

/* 
NOTE: path finder
     0 1 2 3 4                   0 1 2 3 4
     v
0    0 0 1 0 0              0    2 2 1 0 0
1    1 0 1 0 0     --->     1    1 2 1 0 0
2    0 0 0 1 0              2    0 2 2 1 0
3    0 1 0 0 0 <            3    0 1 2 2 2 

(0,0) (0,1) (1,1) (2,1) (2,2) (2,2) (3,2) (3,3) (3,4) // Found!
                        (2,0) (3,0) // DeadEnd
*/
