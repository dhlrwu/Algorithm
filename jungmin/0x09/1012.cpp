#include <bits/stdc++.h>
using namespace std;



int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int T, M, N, K; 
    cin >> T;
    while (T--)
    {
        int board[50][50]{};
        bool vis[50][50]{};
        queue<pair<int, int>> Q;
        cin >> M >> N >> K;

        int x, y, ans = 0; 
        while(K--){
            cin >> x >> y;
            board[x][y] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!board[i][j] || vis[i][j]) continue;
                else {
                    Q.push({i, j});
                    vis[i][j] = true;
                }

                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (!board[nx][ny] || vis[nx][ny]) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                ans++;
            }
        }
        cout << ans << "\n";
    }

}