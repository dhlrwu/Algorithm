#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, pos = 0, iCnt;
	int dat[10001] = {};

	cin >> N;

	for (int i = 0; i < N; i++) {
		
		string op;
		cin >> op;
		if (op == "push") {
			int a;
			cin >> a;
			dat[pos++] = a;
		}
		else if (op == "pop") {
			if (pos > 0) {
				cout << dat[pos - 1] << '\n';
				pos--;
			}
			else cout << -1 << '\n';
		}
		else if (op == "size") {
			cout << pos << '\n';
		}
		else if (op == "empty") {
			if (pos > 0)	
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else {// op == "top"
			if (pos > 0)
				cout << dat[pos - 1] << '\n';
			else
				cout << -1 << '\n';
		}
	}
}