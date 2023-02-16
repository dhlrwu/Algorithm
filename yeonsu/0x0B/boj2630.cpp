#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[130][130]; 
int cnt[2]; // 0 : 하얀색, 1 : 파란색

bool scan(int x, int y, int n) {
    bool tmp = arr[x][y];
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (arr[i][j] != tmp)
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int z) {
    if (scan(x, y, z) == true) {
        cnt[arr[x][y]] += 1;
        return;
    }
    int n = z / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            solve(x + i*n,y + j*n, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    solve(0, 0, n);
    for (int i = 0; i < 2; i++)
        cout << cnt[i] << '\n';
}