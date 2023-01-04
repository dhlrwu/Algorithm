#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;
    if(abs(a-b) <= 1) cout << "0";
    else    
    {
        cout << abs(a-b) - 1 << "\n";
        long long x = min(a, b);
        long long y = max(a, b);
        for(long long i = x + 1; i < y; i++)
            cout << i << " ";
    } 
}

/*
if(a > b) swap(a, b);
으로 더 깔끔하게 짤 수 있다
*/