#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll a, ll b, ll c) {
    if (b == 1)
        return a % c;
    ll n = func(a, b/2, c);
    n = n * n % c;
    if (b%2 == 0)
        return n;
    else 
        return n * a % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}