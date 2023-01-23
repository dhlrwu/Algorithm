#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0; 
    cin >> n;

    while (n--){
        stack<char> stk;
        string s;
        cin >> s;
        
        for (char c : s){
            if (stk.empty()){
                stk.push(c);
                continue;
            }

            if (c == stk.top()){
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }

        if (stk.size() == 0) ans++;

    }

    cout << ans << '\n';
}