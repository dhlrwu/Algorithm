#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
char board[100][100]{};
bool vis[100][100]{};
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[cur.X][cur.Y] != board[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
        
    }
}

int area()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j]) // 방문 안했으면 bfs 돌기 
            {
                q.push({i, j});
                vis[i][j] = true; 
                bfs();
                ans++;
            }

        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    // 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    // bfs
    int notG = area();

    for (int i = 0; i < n; i++)  fill(vis[i], vis[i] + n, false);

    // 적록색약의 경우 초록을 빨강으로 바꿈
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int isG = area();
    cout << notG << " " << isG;
}

