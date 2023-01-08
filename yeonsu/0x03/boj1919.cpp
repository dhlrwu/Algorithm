#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    int sum = 0;
    int charArr[26] = {};

    cin >> s1 >> s2;
    
    for (auto c : s1) charArr[c-'a']++;
    for (auto c : s2) charArr[c-'a']--;

    for (int i : charArr) {
        sum += abs(i);
    }
    cout << sum;
}