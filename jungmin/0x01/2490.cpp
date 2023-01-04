#include <bits/stdc++.h>
using namespace std;

int result, input;
string res = "DCBAE";

int main()
{
    for (int t = 0; t < 3; t++){
        result = 0;

        for (int i = 0; i < 4; i++)
        {
            cin >> input;
            result += input;
        }
        cout << res[result] << "\n";
    }
}