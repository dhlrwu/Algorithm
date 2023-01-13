#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    list<char> str;
    list<char>::iterator cursor;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cursor = str.begin();
        for (char c : s)
        {
            if (c == '-')
                cursor = str.erase(--cursor);

            else if(c == '>')  
                if(cursor != str.end())
                    cursor++;

            else if(c == '<')  // left -> right
            {
                if(cursor != str.begin())
                    cursor--;
            }
            else 
                str.insert(cursor, c);
        }
        
        for (char c : str)
            cout << c;
        cout << '\n';
        str.clear();
    }
}