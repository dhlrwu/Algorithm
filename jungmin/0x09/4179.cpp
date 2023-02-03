#include <bits/stdc++.h>
using namespace std;

char maze[1000][1000]{};
int distF[1002][1002]{};
int distJ[1002][1002]{};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    queue<pair<int, int>> QF;
    queue<pair<int, int>> QJ;
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        fill(distF[i], distF[i] + c, -1);
        fill(distJ[i], distJ[i] + c, -1);
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> maze[i][j];
            if (maze[i][j] == 'J'){
                distJ[i][j] = 0;
                QJ.push({i, j});
            }
            
            if (maze[i][j] == 'F'){
                QF.push({i, j});
                distF[i][j] = 0;
            }
        }
    }

    while (!QF.empty()){
        auto cur = QF.front();
        QF.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (distF[nx][ny] >= 0 || maze[nx][ny] == '#') continue;  // 이미 확산된 지점: distF >= 0

            QF.push({nx, ny});
            distF[nx][ny] = distF[cur.first][cur.second] + 1;
        }
    }

    while (!QJ.empty()){
        auto cur = QJ.front();
        QJ.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << distJ[cur.first][cur.second] + 1;
                return 0;
            }

            if (distJ[nx][ny] >= 0 || maze[nx][ny] == '#') continue;  // 이미 방문한 지점: distF >= 0
            if (distF[nx][ny] != -1 && distF[nx][ny] <= distJ[cur.first][cur.second] + 1) continue; // 지훈이가 가는 시간보다 더 일찍 불이 붙었다면 
            QJ.push({nx, ny});
            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
        }
    }

    cout << "IMPOSSIBLE";
}
