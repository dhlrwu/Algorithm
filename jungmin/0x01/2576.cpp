#include <bits/stdc++.h>
using namespace std;


int main()
{
    int sum = 0, minimum = 100, input;

    for (int i = 0; i < 7; i++)
    {
        cin >> input;
        if (input % 2 != 0) {
            sum += input;
            minimum = min(input, minimum);
        }
    }
    if (sum == 0)
        cout << "-1";
    else
        cout << sum << "\n" << minimum;
}


