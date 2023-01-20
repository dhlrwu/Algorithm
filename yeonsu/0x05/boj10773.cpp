#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, sum = 0;
    stack<int> st;
    cin >> K;

    while (K--) {
        int a;
        cin >> a;
        if (a == 0){
            sum -= st.top();
            st.pop();
        }
        else{
            sum += a;
            st.push(a);
        }
    }
    cout << sum;
}