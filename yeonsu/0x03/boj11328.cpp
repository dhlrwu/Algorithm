#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        string result = "Possible";
        int charArr[26] = {};
        int testArr[26] = {};
        cin >> s1 >> s2;

        for (int j = 0; j < s1.length(); j++) {
            int idx = s1[j] - 'a';
            charArr[idx]++;
        }
        for (int j = 0; j < s2.length(); j++) {
            int idx = s2[j] - 'a';
            testArr[idx]++;
        }
        
        for (int l = 0; l < 26; l++) {
            if (charArr[l] != testArr[l]){
                result = "Impossible";
                break;
            }
        }
        cout << result << "\n";

    }
}