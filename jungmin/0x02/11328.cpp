#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, alpha[26]{};
    cin >> N;
    while (N--)
    {
        string s1, s2;
        int i;
        cin >> s1 >> s2;
        if(s1.length() != s2.length())
        {
            cout << "Impossible\n";
            continue;
        }
        for(i = 0; i < s1.length(); i++)
        {
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;
        }
        for(i = 0; i < 26; i++){
            if(alpha[i]) {
                cout << "Impossible\n";
                break;
            }            
        }
        if (i == 26)
            cout << "Possible\n";

        fill(alpha, alpha+26, 0);
    }
}
