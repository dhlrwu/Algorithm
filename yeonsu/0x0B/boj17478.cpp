#include <bits/stdc++.h>
using namespace std;
int tmp = -1;

void func(int n) {
    tmp++;
    string str;
    for (int  i = 0; i < tmp; i++) {
        str.append("____");
    }

    cout << str << "\"����Լ��� ������?\"\n";
    if (n == 0) { // ���������� �亯
        cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << str << "��� �亯�Ͽ���.\n";
        return;
    }
    cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"
        << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"
        << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    func(--n);
    cout << str << "��� �亯�Ͽ���.\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    func(n);
}