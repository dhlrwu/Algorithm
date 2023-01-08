#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int arr[26];
    int idx;
    cin >> str;
    
    fill(arr, arr + 26, 0); //arr을 전역변수로 선언한 경우, 초기화 작업 불필요

    for (int i = 0; i < str.size(); i++) { // 
        idx = str[i] - 'a';
        arr[idx] = arr[idx] + 1;
    }

    for (int i = 0; i < 26; i++){
        cout << arr[i];
        cout << " ";
    }
}