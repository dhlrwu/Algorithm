#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[3];
int arr[2200][2200];

bool scan(int x, int y, int a) {
    int tmp = arr[x][y];
    for (int i = x; i < x+a; i++) {
        for (int j = y; j < y+a; j++) {
            if (arr[i][j] != tmp)
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int z) {
    //스캔 후 같다면 그대로 종이 사용
    if (scan(x, y, z) == true) {
        cnt[arr[x][y]+1] += 1;
        return;
    }
    int n = z / 3; // 3*3 = 9 구역으로 나눔
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            solve(x + i*n, y + j*n, n);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    solve(0, 0, n);
    cout << cnt[0] << '\n'
        << cnt[1] << '\n'
        << cnt[2] << '\n';
}