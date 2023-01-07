#include <bits/stdc++.h>
using namespace std;

int arr[100001];
bool occur[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (x-arr[i] > 0 && occur[x-arr[i]])
            answer++;
        occur[arr[i]] = true;
    }
    cout << answer;
}