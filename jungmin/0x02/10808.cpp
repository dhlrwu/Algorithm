#include <bits/stdc++.h>
using namespace std;

int main()
{
    int alphabet[26]{};
    string s;
    cin >> s;

    for (char c : s)
        alphabet[c-97]++;

    for (int i : alphabet)
        cout << i << ' ';
}

