#include <iostream>
#include <list>
using namespace std;

list<char> char_list;
int m;
list<char>::iterator cursor;

void printList()
{
    for (char c : char_list)
        cout << c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s >> m;

    for (char c : s)
        char_list.push_back(c);

    cursor = char_list.end();
    while (m--)
    {
        char c, input;
        cin >> c;

        if (c == 'L')
        {
            if (cursor != char_list.begin())
                cursor--;
        }
        else if (c == 'D')
        {
            if (cursor != char_list.end())
                cursor++;
        }
        else if (c == 'B')
        {
            if (cursor != char_list.begin())
                cursor = char_list.erase(--cursor);
        }
        else 
        {
            cin >> input;
            char_list.insert(cursor, input);
        }
    }

    printList();
}

/*
list의 end()는 마지막 원소 다음을 가리킴. 즉 아무것도 없는 것을 가리키기때문에 dereferencing 불가 
list의 erase()는 포인터가 가리키는 원소 제거 후 제거된 원소의 nxt를 반환 // 연결리스트에서의 nxt임 
list의 insert()는 포인터의 앞에 원소 추가, 그리고 포인터는 변하지 않음  // insert(itr, 'b'); // a b c   c앞에 b가 추가되어도 여전히 c를 가리킨다는 뜻 
*/