#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n;
    deque<int> deq;

    cin >> t;
    while (t--)
    {
        deq.clear();
        bool isError = false, head = true;
        string p, arr;
        cin >> p >> n >> arr;

        int num = 0;
        if (n > 0) {  // 배열 원소가 한개 이상이면 
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i] == ',' || arr[i] == ']') {   // , 나 ] 에서 push 
                    deq.push_back(num);
                    num = 0;
                    continue;
                }
                num = num * 10 + (arr[i] - 48);   // 2자리 이상일 수 있으므로 
            }
        }

        for (char c : p) {
            if (c == 'D') {    // delete 명령 
                if (!deq.empty()) {    // 비어있지 않은 상태
                    if (head) deq.pop_front();   // head면 앞에 삭제 
                    else deq.pop_back();   // 아니면 뒤에 삭제 
                }
                else {
                    isError = true;  // 비어있는데 delete 시도했으므로 error 
                }
            }
            else { // c == 'R'   // reverse 명령 head 바꿈 
                head = !head;
            }
        }

        if (isError) {  // 에러가 난 경우이면 
            cout << "error" << "\n";
        }
        else {
            cout << "[";
            if (!head) {
                reverse(deq.begin(), deq.end());
            }
            for (int i = 0; i < deq.size(); i++) {
                cout << deq[i];
                if (i != deq.size() - 1)
                    cout << ",";
            }
            cout << "]\n";
        }
    }
}
