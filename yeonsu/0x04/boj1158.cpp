#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <int> V, answer;

    for (int i = 1; i < n+1; i++) {
        V.push_back(i);
    }
    for (int i = 0; answer.size() < n; i++) {
        if (i % k == k - 1)
            answer.push_back(V[i]);
        else V.push_back(V[i]);
    }
    cout << '<';
    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << answer[i];
        else cout << answer[i] << ", ";

    }
    cout << '>';
 }