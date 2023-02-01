#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101][101];
int dist[101][101][101];
queue <tuple<int, int, int>> Q;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, h;
    cin >> m >> n >> h;
    //입력받아서 board 세팅
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    Q.push({i, j, k});
                if (board[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }
    //bfs 진행
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        //get<>(cur)대신 std::tie() 이용
        //int curX, curY, curZ;
        //tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (dist[nx][ny][nz] >= 0) // 갈 수 없거나 방문한 적 있거나
                continue;
            Q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
    //답 출력
    int ans = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 토마토가 모두 익지 못하는 상황
                if (dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans;
}