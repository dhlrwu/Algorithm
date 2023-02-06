#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    stack<int> s;
    int k;
    cin >> k;

    int sum = 0;
    while (k--)
    {
        int input; 
        cin >> input;

        if(input){
            s.push(input);
            sum += input;
        }
        else{
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum;
}