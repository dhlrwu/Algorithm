#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;

    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push_front"){
            int val;
            cin >> val;
            DQ.push_front(val);
        }
        else if (op == "push_back"){
            int val;
            cin >> val;
            DQ.push_back(val);
        }
        else if (op == "pop_front"){
            if (DQ.empty()){
                cout << -1 << '\n';
            }
            else {
                int val = DQ.front();
                DQ.pop_front();
                cout << val << '\n';
            }
        }
        else if (op == "pop_back"){
            if (DQ.empty()){
                cout << -1 << '\n';
            }
            else {
                int val = DQ.back();
                DQ.pop_back();
                cout << val << '\n';
            }
        }
        else if (op == "size"){
            cout << DQ.size() << '\n';
        }
        else if (op == "empty"){
            cout << DQ.empty() << '\n';
        }
        else if (op == "front"){
            if (DQ.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << DQ.front() << '\n';
            }
        }
        else if (op == "back"){
            if (DQ.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << DQ.back() << '\n';
            }
        }
    }
}