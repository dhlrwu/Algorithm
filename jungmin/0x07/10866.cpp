#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[2*MX + 1];
int head = MX, tail = MX;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        if (s == "push_front"){
            cin >> dat[--head];
        }
        else if (s == "push_back"){

            cin >> dat[tail++];
        }
        else if (s == "pop_front"){
            if (head == tail){
                cout << -1 << '\n';
            }
            else{
                cout << dat[head++] << '\n';
            }
        }
        else if (s == "pop_back"){
            if (tail == head){
                cout << -1 << '\n';
            }
            else{
                cout << dat[--tail] << '\n';
            }
        }
        else if (s == "size"){
            cout << tail - head << '\n';
        }
        else if (s == "empty"){
            if (tail - head) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (s == "front"){
            if (head == tail){
                cout << -1 << '\n';
            }
            else{
                cout << dat[head] << '\n';
            }
        }
        else{
            if (tail == head){
                cout << -1 << '\n';
            }
            else{
                cout << dat[tail - 1] << '\n';
            }
        }
    }
}

// head는 가장 앞에 있는 원소의 index
// tail은 가장 뒤에 있는 원소 index + 1