#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    stack<char> left, right;

    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for (char c : s)
        {
            if(isalnum(c))  // 알파벳 숫자 
                left.push(c);

            else if(c == '>')  // right -> left
            {
                if(!right.empty())
                {
                    left.push(right.top());
                    right.pop();
                }
            }

            else if(c == '<')  // left -> right
            {
                if(!left.empty())
                {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if (c == '-')
            {
                if(!left.empty())
                    left.pop();
            }
        }
        
        while(!left.empty())
        {
            right.push(left.top());
            left.pop();
        }
        while(!right.empty())
        {
            cout << right.top(); 
            right.pop();
        }
        cout << '\n';
    }

}