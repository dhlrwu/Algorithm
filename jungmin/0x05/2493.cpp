#include <iostream>
#include <stack>

using namespace std;

int arr[500000]{};
int rcv[500000]{};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    stack<int> left;  // index
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            rcv[i] = i;
            while (!left.empty() && arr[left.top()] < arr[i - 1]) {
                rcv[left.top()] = i;
                left.pop();
            }
        }
        else left.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << rcv[i] << ' ';
    }
}

/*
앞에서부터 바로 처리하는 방법 
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/2493.cpp
*/