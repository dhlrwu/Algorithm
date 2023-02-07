#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        bool isPossible = false;
        queue<pair<int, int>> Q1, Q2;
        cin >> m >> n;
        // 초기화
        for (int i = 0; i < n; i++)  {
            fill (dist1[i], dist1[i]+m, -1);
            fill (dist2[i], dist2[i]+m, -1);
        }
        // board 세팅
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '*'){
                    Q1.push({i, j});
                    dist1[i][j] = 0;
                }
                if (board[i][j] == '@'){
                    Q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }
        // 불 bfs 진행
        while(!Q1.empty()) {
            auto cur = Q1.front();
            Q1.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
                    continue;
                Q1.push({nx, ny});
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            }
        }
        // 상근 bfs 진행
        while(!Q2.empty() && !isPossible) {
            auto cur = Q2.front();
            Q2.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                // 범위 벗어나야 성공
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist2[cur.X][cur.Y] + 1 << '\n';
                    isPossible = true;
                    break;
                }
                if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
                    continue;
                if (dist1[nx][ny] > -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                    continue;
                Q2.push({nx, ny});
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            }
        }
        if (!isPossible)
            cout << "IMPOSSIBLE\n";
    }
}