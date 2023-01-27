#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[501][501]{};
bool vis[501][501]{};
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, cnt = 0, num = 0, maximum = 0; 
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    // bfs 
    queue<pair<int, int>> que;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (vis[i][j] || !board[i][j]) continue;
            que.push({i, j});
            vis[i][j]  = true;
            cnt = 0;
            while (!que.empty()){
                pair<int, int> cur = que.front();
                que.pop();
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (vis[nx][ny] || !board[nx][ny]) continue;
                    que.push({nx, ny});
                    vis[nx][ny] = true;
                }
                cnt++;
            }
            num++;
            maximum = max(cnt, maximum);
        }
    }
    cout << num << '\n' << maximum;
}