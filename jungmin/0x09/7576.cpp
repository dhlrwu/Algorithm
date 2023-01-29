#include <bits/stdc++.h>
using namespace std;

int box[1001][1001]{};
bool vis[1001][1001]{};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct node {
    int x;
    int y;
    int day;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n, cnt = 0, emptycnt = 0, ans = 0;
    queue<node> Q;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {  // 익은 토마토라면 q에 넣어둠 
                Q.push({ i, j, 0 });
                vis[i][j] = true;
                cnt++;
            }
            else if (box[i][j] == -1){
                vis[i][j] = true;
                emptycnt++;
            }
        }
    }

    while (!Q.empty()) {
        node cur = Q.front();
        int nday = cur.day;
        Q.pop();
        ans = nday;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!vis[nx][ny] && box[nx][ny] == 0) {
                Q.push({ nx, ny, nday + 1 });
                vis[nx][ny] = true;
                cnt++;
            }
        }
    }

    // 익은 토마토 개수 < 전체 판의 개수 - 빈 공간 
    if (cnt < n * m - emptycnt)
        cout << -1;
    else
        cout << ans;
}