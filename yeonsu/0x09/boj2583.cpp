#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[101][101];
vector<int> cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> Q;
int m, n, k;
int rectSize;

void check(int x1, int y1, int x2, int y2) {
    // 직사각형 칸은 vis -1로 초기화
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2;j++) {
            vis[i][j] = -1; 
        }
    }
}

void bfs(int a, int b) {
    rectSize = 1; 
    Q.push({a, b});
    vis[a][b] = 1;
    while(true) {
        if (Q.empty()) {
            cnt.push_back(rectSize);
            break;
        }

        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] != 0)
                continue;
            Q.push({nx, ny});
            rectSize++;
            vis[nx][ny] = rectSize;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // (x1, y1) ~ (x2, y2)
        check(x1, y1, x2, y2);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    
    // 답 출력 - 오름 차순 정렬
    cout << cnt.size() << '\n';
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << ' ';
    }
}