#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        stack<int> st;
        
        for (auto c : s) {
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);     
        }
        if (st.empty())
            sum++;
    }
    cout << sum;
}