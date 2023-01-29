#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//int board[200001];
int dist[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;

    fill(dist, dist+100001, -1);

    dist[n] = 0;
    Q.push(n);
    while(dist[k] == -1) {
        auto cur = Q.front();
        Q.pop();
        int dx[3] = {cur - 1, cur + 1, cur * 2};
        //cout << d[0] << ' ' << d[1] << ' '  << d[2] << '\n'; 
        for (int i = 0; i < 3; i++) {
            if (dx[i] < 0 || dx[i] > 100000) // 배열 범위
                continue;
            if (dist[dx[i]] != -1) // 방문했거나 갈 수 없다면
                continue;
            dist[dx[i]] = dist[cur]+1;
            Q.push(dx[i]);
        }
    }
    cout << dist[k];
}