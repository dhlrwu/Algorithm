#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[301][301];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        queue <pair<int, int>> Q;
        int n;
        int a, b;
        int x, y;
        cin >> n;
        // 현재 위치 받기
        cin >> a >> b;
        // 목표 위치 받기
        cin >> x >> y;
        //초기화
        for (int i = 0; i < n; i++) {
            fill(dist[i], dist[i]+n, -1);
        }
        // bfs() 진행
        Q.push({a, b});
        dist[a][b] = 0;
        while (dist[x][y] == -1) {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] >= 0)
                    continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
                // cout << "큐에 push : "<< nx << ' ' << ny 
                //     << " dist값 : " << dist[nx][ny] <<'\n';
            }
        }
        // 답 출력
        cout << dist[x][y] << '\n';
    }
}