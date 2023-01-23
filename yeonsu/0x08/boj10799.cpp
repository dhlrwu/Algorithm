#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0;
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            if (s[i+1] == ')') { // lazer인 경우
                ans += st.size();
                i++;
                continue;
            }
            st.push('(');
            ans++;
        }
        else if (s[i] == ')') {
            st.pop();
        }
    }
    cout << ans;
}