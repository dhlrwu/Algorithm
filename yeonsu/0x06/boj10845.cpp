#include <bits/stdc++.h>
using namespace std;

//STL queue 활용
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> Q;

    while(n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int a;
            cin >> a;
            Q.push(a);
        }
        else if (op == "pop") {
            if (Q.empty())  cout << -1 << "\n";
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (op == "size") {
            cout << Q.size() << "\n";
        }
        else if (op == "empty") {
            cout << Q.empty() << "\n";
        }
        else if (op == "front") {
            if (Q.empty())  cout << -1 << "\n";
            else {
                cout << Q.front() << "\n";
            }       
        }
        else { // back
            if (Q.empty())  cout << -1 << "\n";
            else {
                cout << Q.back() << "\n";
            }
        }
    }

}