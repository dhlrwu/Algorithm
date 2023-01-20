#include <bits/stdc++.h>
using namespace std;
const int MX = 100001;
int dat[MX];
int head, tail;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;
        if (op == "push"){
            int val;
            cin >> val;
            push(val);
        }
        else if (op == "pop") {
            if (tail == head) {
                cout << -1 << "\n";
            }
            else {
                cout << front() << "\n";
                pop();
            }
        }
        else if (op == "size") {
            cout << tail-head << "\n";
        }
        else if (op == "empty") {
            cout << (tail==head) << "\n"; 
        }
        else if (op == "front"){
            if (tail != head)
                cout << front() << "\n";
            else
                cout << -1 << "\n";
        }
        else { // back
            if (tail != head)
                cout << back() << "\n";
            else
                cout << -1 << "\n";
        }
    }
}


