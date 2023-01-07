#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int sum = a*b*c;
    string s = to_string(sum);
    
    for(int i = 0; i < s.length(); i++) {
        int j = s[i] - '0';
        arr[j] = arr[j] + 1;
    }   

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }
}