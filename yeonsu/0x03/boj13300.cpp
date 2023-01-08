#include <bits/stdc++.h>
using namespace std;

int arr[6][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, answer = 0;
    cin >> n;
    cin >> k;

    // 여자는 1, 남자는 0 - 학년 표시
    for (int i = 0; i < n; i++) {
        int gender, grade;
        cin >> gender;
        cin >> grade;
        arr[grade-1][gender] = arr[grade-1][gender] + 1;
    }

    for (int j = 0; j < 6; j++) {
        for (int l = 0; l < 2; l++){
            double a = (double)arr[j][l] / k;
            answer += ceil(a);
        }
    }
    cout << answer;
}