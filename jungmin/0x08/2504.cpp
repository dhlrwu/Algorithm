#include <bits/stdc++.h>
using namespace std;

stack<char> S;  // 괄호
stack<pair<int, int>> op; // 값, 레벨 
int main()
{
    string s;
    cin >> s;

    int lv = -1, ans = 0;
    for (char c : s){
        if (c == '(' || c == '['){
            S.push(c);
            lv++;
        }

        if ((S.top() == '(' && c == ']') || S.top() == '[' && c == ')') {
            cout << 0;
            return 0;
        }

        int res = 0;
        if (c == ')') res = 2;
        else res = 3;

        if (c == ')' && S.top() == '('){
            res = 2; 
            
        }

        
    }
}

void calculate(char c){

}
// (([]))