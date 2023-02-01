#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[101];
bool vis[101][101];
queue <pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n;

void bfs(int x, int y, bool isColorWeak) {
    Q.push({x, y});
    vis[x][y] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (isColorWeak) {
                // ������ ���� ���� �ٸ� ���  rg, rb, gb �� ��� �����ϰ� ��
                // ������ ��� gb, rb �� ��츸 �ɷ��� �� (rg�� ���)
                // R 82 G 71 B 66
                if (vis[nx][ny])
                    continue;
                if (board[nx][ny] != board[cur.X][cur.Y]) {
                    if (abs(board[nx][ny] - board[cur.X][cur.Y]) != 11) // RG���� 
                        continue;
                }
            }
            else {
                if (board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny])
                continue;
            }
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int ans1 = 0, ans2 = 0;
    //����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, false);
                ans1++;
            }
        }
    }
    //�ʱ�ȭ
    for (int i = 0; i < n; i++) {
        fill (vis[i], vis[i] + n, 0);
    }
    //���ϻ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, true);
                ans2++;
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}