#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int maze[101][101]{};
bool vis[101][101]{};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            maze[i][j] = s[j]- '0';
        }
    }

    queue<pair<int, pair<int, int>>> Q;  // 칸 수, 좌표
    Q.push({1, {0, 0}});
    vis[0][0] = true;

    while (!Q.empty()){
        int mn = Q.front().first;
        pair<int, int> cur = Q.front().second;
        Q.pop();

        if (cur.X == n - 1  && cur.Y == m - 1) {
            ans = mn;
            break;
        }


        for (int dir = 0; dir < 4; dir++){
            // push 할 것들 추리기 

            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || !maze[nx][ny]) continue;

            Q.push({mn + 1, {nx, ny}});
            vis[nx][ny] = true;
        }
    }
    cout << ans;
}