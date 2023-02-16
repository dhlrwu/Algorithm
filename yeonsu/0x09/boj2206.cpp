#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001][2]; // [0] : 벽 안 부수는 경우, [1] : 벽을 부수는 경우
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
queue <tuple<int, int, int>> q;
int m, n;

int bfs() {
    // dist 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = dist[0][0][1] = 1;
    q.push({0, 0, 0});
    cout << "0 0 0\n"; 
    while(!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        // 도착했다면
        if (x == n-1 && y == m-1)
            return dist[x][y][broken];
        q.pop();
        int nextdist = dist[x][y][broken] +1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 갈 수 있는 경우
            if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1) { 
                dist[nx][ny][broken] = nextdist;
                q.push({nx, ny, broken});
                cout << nx << ' ' << ny << ' ' << broken << '\n';
            }
            // 부수는 경우
            if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nextdist;
                q.push({nx, ny, 1});
                cout << nx << ' ' << ny << ' ' << 1 << '\n';
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // board 세팅
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            board[i][j] = str[j] - '0';
        }
    }
    cout << bfs();
}