#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    deque<int> dq;
    int n, m, ans = 0;   
    int left = 0, right;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    while(m--){
        int input;
        cin >> input;

        right = dq.size() - 1;

        int idx = 0;
        while (dq[idx] != input){
            idx++; // idx는 input이 덱에서 위치한 index가 됨 
        }

        // 2번 연산 : left가 더 가까움 
        if (idx * 2 <= right){
            while (dq.front() != input)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        }
        else { // 3번 연산 
            while (dq.front() != input)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }

    cout << ans;
}
// 왼쪽 오른쪽 어디가 더 가까운지 
