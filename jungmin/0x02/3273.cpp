#include <bits/stdc++.h>
using namespace std;

int n, x, ans = 0, num[100001]{};
bool arr[1000001]{};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> num[i];    
        arr[num[i]] = 1;
    }
    cin >> x;

    for (int i = 1; i <= n; i++)
    {
        int a = x - num[i];
        if(a <= 0 || a > 1000000 || a == num[i]) continue;

        if(arr[a]) {
            ans++;
            arr[a] = 0;
            arr[num[i]] = 0;
        }
    }
    cout << ans;
}
