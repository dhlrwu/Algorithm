#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x;
    int y;
    int z;
};

int n, m, h;
int box[100][100][100]{};
int dist[100][100][100]{};
queue<pos> q;

int dx[6] = { 1, 0, 0, -1, 0, 0 };  // right top forward left bottom back
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

// n은 행의 개수
// m은 열의 개수
// 한 행에 좌르륵 입력받아야 되니까 n이 바깥 for 문 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) { // i는 높이 
        for (int j = 0; j < n; j++) { // j는 행 번호 
            for (int k = 0; k < m; k++) {  // k는 열 번호 
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)  q.push({ j, k, i });
                else if (box[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nz][nx][ny] >= 0 || box[nz][nx][ny] == -1) continue; // 이미 익었거나 토마토가 없는 칸 

            q.push({ nx, ny, nz });
            dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dist[i][j][k] < 0) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout << ans;
}