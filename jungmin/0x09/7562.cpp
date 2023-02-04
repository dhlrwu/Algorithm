#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dist[300][300];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;

    cin >> t;
    while (t--)
    {
        int ans = 0;
        int n, x, y, destX, destY;
        queue<pair<int, int>> q;

        cin >> n >> x >> y >> destX >> destY;

        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);

        q.push({x, y});
        dist[x][y] = 0;

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            if (cur.X == destX && cur.Y == destY) {
                ans = dist[cur.X][cur.Y];
                break;
            }

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] >= 0) continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        cout << ans << '\n';
    }
}