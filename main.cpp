#include <iostream>
#include "Tree.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tree bt;
    int n;
    string str;
    int lvl;
    cout<<"������� ���-�� ����� � ������\n";
    cin>>lvl;
    cout<<"������� ���� ������:\n";
    for(int i = 0; i < lvl; i++){
          cout<<"�����:";
          cin>>str;
          cout<<"���-�� ����� � ������:";
          cin>>n;
        // int n = rand() % 20-10;
        // string str = "�����";

        bt.addEl(n, str);

    }
    cout << endl;

    //����� ������
    bt.showtree(lvl);

    //�������� ������
    bt.del();
    cout << endl;
    cout << endl;

    //�������� �����
    bt.showtree1();

    cout << endl;
    cout<<"���-�� ����������:";
    cout<<bt.numOfMax();

    return 0;
}
