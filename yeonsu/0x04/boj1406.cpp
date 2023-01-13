#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr]; 
}

void traversal() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    string s;
    cin >> s;
    int cursor = 0;
    for (int i = 0; i < s.length(); i++) {
        insert(cursor, s[i]);
        cursor++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == 'P') {
            char add;
            cin >> add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
        else if (op == 'L') {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        }
        else if (op == 'D') {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        }
        else {
            if (cursor != 0) {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }
    traversal();
}