#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {   
        string str;
        bool isValid = true;
        stack<char> st;
        getline(cin, str);
        if (str == ".")
            break;
        
        for (auto c : str) {
            if (c == '(' || c == '['){
                st.push(c);
            }
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    isValid = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.empty() == 0)
            isValid = false;
        
        if (isValid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}