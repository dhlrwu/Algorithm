#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[500][500];
bool vis[500][500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int MX = 0;

void bfs(int i, int j, int n, int m) {
    queue<pair<int, int>> Q;
    int tmp = 0;

    vis[i][j] = 1;
    Q.push({i, j});
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        tmp++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    MX = max(MX, tmp);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int ans = 0;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //초기 board 세팅
            cin >> board[i][j];
        }
    }
    // 이중 for문으로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                //시작점이 될 수 있음
                bfs(i, j, n, m);
                ans++;
            }
        }
    }

    cout << ans << '\n';
    cout << MX << '\n';

}