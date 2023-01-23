#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    int num = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        }
        else if (s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }

            if (s[i-1] == '(') { // () 인 경우
                ans += num;
            }
            st.pop();
            num /= 2;
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i-1] == '[') { // [] 인 경우
                ans += num;
            }
            st.pop();
            num /= 3;
        }
    }
    if (st.empty()) cout << ans;
    else cout << 0;
}