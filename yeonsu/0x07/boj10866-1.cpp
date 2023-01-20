#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push_front"){
            int val;
            cin >> val;
            dat[--head] = val;
        }
        else if (op == "push_back"){
            int val;
            cin >> val;
            dat[tail++] = val;
        }
        else if (op == "pop_front"){
            if (tail == head){
                cout << -1 << '\n';
            }
            else {
                cout << dat[head] << '\n';
                head++;
            }
        }
        else if (op == "pop_back"){
            if (tail == head){
                cout << -1 << '\n';
            }
            else {
                cout << dat[tail-1] << '\n';
                tail--;
            }
        }
        else if (op == "size"){
            cout << tail - head << '\n';
        }
        else if (op == "empty"){
            cout << (tail == head) << '\n';
        }
        else if (op == "front"){
            if (tail == head){
                cout << -1 << '\n';
            }
            else {
                cout << dat[head] << '\n';
            }
        }
        else if (op == "back"){
            if (tail == head){
                cout << -1 << '\n';
            }
            else {
                cout << dat[tail-1] << '\n';
            }
        }
    }
}