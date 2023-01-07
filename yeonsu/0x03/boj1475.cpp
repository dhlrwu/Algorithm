#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;

    cin >> num;
    for (int i = 0; i < num.length(); i++) {
        int t = num[i] - '0';
        arr[t] = arr[t] + 1;
    }
    
    double mean = ((double)arr[6] + arr[9]) / 2;
    int max = floor(mean + 0.5);

    arr[6] = 0;
    arr[9] = 0;

    for (int i = 0; i < 10; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << max;
}