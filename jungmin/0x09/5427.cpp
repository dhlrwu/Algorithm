#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t, w, h;
char board[1000][1000]{};
int distF[1000][1000]{};
int distS[1000][1000]{};
queue<pair<int, int>> F;
queue<pair<int, int>> S;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--)
    {
        // 입력 
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            fill(distF[i], distF[i] + w, -1);
            fill(distS[i], distS[i] + w, -1);

            for (int j = 0; j < w; j++){
                char tmp;
                cin >> tmp;
                board[i][j] = tmp;
                
                if (tmp == '@')  // 상근 
                {
                    S.push({i, j});
                    distS[i][j] = 0;
                }

                if (tmp == '*')  // 불 위치면 
                {
                    F.push({i, j});
                    distF[i][j] = 0;
                }
            }

        }

        // 불 bfs
        while (!F.empty())
        {
            auto cur = F.front();
            F.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (distF[nx][ny] >= 0 || board[nx][ny] == '#') continue;

                F.push({nx, ny});
                distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            }
        }

        bool isEscape = false;
        while (!S.empty() && !isEscape)
        {
            auto cur = S.front();
            S.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << distS[cur.X][cur.Y] + 1 << "\n";
                    isEscape = true;
                    break;
                }

                if (distS[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if (distF[nx][ny] >= 0 && distF[nx][ny] <= distS[cur.X][cur.Y] + 1) continue;

                S.push({nx, ny});
                distS[nx][ny] = distS[cur.X][cur.Y] + 1;
            }
        }
        if (!isEscape) cout << "IMPOSSIBLE\n";
    }
    
}