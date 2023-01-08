#include <bits/stdc++.h>
using namespace std;

int num[100001]{};
bool arr[2000001]{};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> num[i];    
    }
    cin >> x;

    for (int i = 1; i <= n; i++)
    {
        if (x - num[i] > 0 && arr[x - num[i]])
            ans++;
        arr[num[i]] = true;
    }
    cout << ans;
}
