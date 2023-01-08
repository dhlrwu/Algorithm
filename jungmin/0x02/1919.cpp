#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int ans = 0, a1[26]{}, a2[26]{};
    string s1, s2;
    cin >> s1 >> s2;

    for(char c : s1) a1[c-'a']++;
    for(char c : s2) a2[c-'a']++;

    for(int i = 0; i < 26; i++)
    {   
        if(a1[i] == a2[i]) continue; 
        ans += abs(a1[i] - a2[i]);
    }
    cout << ans;
}