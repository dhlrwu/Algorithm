#include <bits/stdc++.h>
using namespace std;

int arr[100]; //1~100 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> v;

    for (int i = 0; i < n; i++) {
        if (arr[i] == v)
            answer++;
    }
    cout << answer;
}