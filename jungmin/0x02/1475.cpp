#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int set[10]{};
    int N, res = 0;
    cin >> N;

    while(N)
    {
        set[N%10]++;
        N /= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        if(i == 6 || i == 9) continue;
        res = max(res, set[i]);
    }
    res = max(res, (set[6]+set[9] + 1)/2);

    cout << res;
}

