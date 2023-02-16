#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[65][65];

bool scan(int x, int y, int n) {
    bool tmp = arr[x][y];
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++)
            if (arr[i][j] != tmp) 
                return false;
    }
    return true;
}

void solve(int x, int y, int z) {
    if (scan(x, y, z) == true) {
        cout << arr[x][y];
        return;
    }
    int n = z / 2;
    cout << '(';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            solve(x + n*i, y + n*j, n);
    }
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            arr[i][j] = (str[j] - '0' == 1) ? true : false;
            j++;
        }
    }
    solve(0, 0, n);
}