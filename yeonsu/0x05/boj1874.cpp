#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    stack<int> st;
    int cnt = 1;
    string ans;
    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
            st.push(cnt++);
            ans += "+\n";
        }
        if (st.top() != t) {
            cout << "NO\n";
            return 0;
        }

        cout << "t, cnt : " << t <<" " << cnt << "\n";
        st.pop();
        ans += "-\n";
    }
    cout << ans;

}