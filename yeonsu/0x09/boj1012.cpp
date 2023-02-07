#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[51][51];
bool vis[51][51];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

void bfs(int i, int j) {
    Q.push({i, j});
    vis[i][j] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        
        //입력받으면서 배추 세팅
        while(k--) {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }
        int res = 0; // 지렁이 개수 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }

        // 답 출력
        cout << res << '\n';
        // 초기화
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, false);
        }
    }
    return 0;
}
