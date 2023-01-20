#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& DQ) {
    int cur = 0;
    for (int i = 1; i+1 < tmp.size(); i++) {
        if (tmp[i] == ',') {
            DQ.push_back(cur);
            cur = 0;
        }
        else {
            cur = 10 * cur + (tmp[i]-'0');
        } 
    }
    if (cur != 0)
        DQ.push_back(cur);
}

void print(deque<int>& DQ) {
    cout << '[';
    for (int i = 0; i < DQ.size(); i++) {
        cout << DQ[i];
        if (i+1 != DQ.size()) {
            cout << ',';
        }
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string query, tmp;
        int n;
        deque<int> DQ;
        int rev = 0;
        bool isWrong = false;
        cin >> query >> n >> tmp;
        // 덱 세팅
        parse(tmp, DQ);
        // 명령어대로 수행
        for (char c : query) {
            if (c == 'R') {
                rev = 1 - rev;
            }
            else {
                if (DQ.empty()) {
                    isWrong = true;
                    break;
                }
                if (!rev) {
                    DQ.pop_front();
                }
                else {
                    DQ.pop_back();
                }
            }
        }
        // 배열 출력
        if (isWrong) {
            cout << "error\n";
        }
        else {
            if (rev)
                reverse(DQ.begin(), DQ.end());
            print(DQ);
        }
    }
}