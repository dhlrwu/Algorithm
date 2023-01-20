#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> DQ;
    int N, M, ans = 0, pos;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        DQ.push_back(i);
    while (M--) {
        int n;
        cin >> n;
        // pos에 대해 이렇게 for문 말고,
        // find()함수를 사용하여 알아낼 수 있음
        // pos = find() - DQ.begin()
        for (int i = 0; i < DQ.size(); i++) {
            if (DQ[i] == n){
                pos = i;
                break;
            }
        }
        while (DQ.front() != n) {
            // if 조건문에서도
            // pos < DQ.size - pos 
            // 나눠버리면 int라서 소수점 관련 애매해짐
            if (pos <= DQ.size()/2){ 
                int val = DQ.front();
                DQ.pop_front();
                DQ.push_back(val);
                //DQ.push_back(DQ.front());
                //DQ.pop_front();
                //순서로 바꿔서 int val 선언 불필요
            }
            else {
                int val = DQ.back();
                DQ.pop_back();
                DQ.push_front(val);
            }
            ans++;
        }
        DQ.pop_front();
    }
    cout << ans;
}