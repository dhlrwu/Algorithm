#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t = 1;
    cin >> n;
    queue<int> Q;

    for (int j = 1; j <= n; j++) {
        Q.push(j);
    }
    while (Q.size() != 1) {
        Q.pop();
        int val = Q.front();
        Q.push(val);
        Q.pop();
    }
    cout << Q.front();
}