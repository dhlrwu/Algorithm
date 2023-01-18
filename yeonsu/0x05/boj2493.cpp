#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> St;

    St.push({100000001, 0});
    for (int a = 1; a <= n; a++) {
        int height;
        cin >> height; 
        while (St.top().first < height)
            St.pop();
        cout << St.top().second << " ";
        St.push({height, a});
    }
    
}