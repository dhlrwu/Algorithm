#include <bits/stdc++.h>
using namespace std;

int student[2][6]{};
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        student[a][b-1]++;   // 학년은 1-6으로 입력하니까
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 6; j++){
            ans += student[i][j] / k;
            if(student[i][j] % k != 0) ans++;
        }
    }

    cout << ans;
}

/*
    한 방 - 1 ~ k명/ 같은 학년 / 같은 성별
*/