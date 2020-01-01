#include <iostream>
#include "Tree.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    Tree bt;
    int n;
    string str;
    int lvl;
    cout<<"Введите кол-во узлов в дереве\n";
    cin>>lvl;
    cout<<"Введите узлы дерева:\n";
    for(int i = 0; i < lvl; i++){
          cout<<"Текст:";
          cin>>str;
          cout<<"Кол-во цифра в тексте:";
          cin>>n;
        // int n = rand() % 20-10;
        // string str = "текст";

        bt.addEl(n, str);

    }
    cout << endl;

    //вывод дерева
    bt.showtree(lvl);

    //удаление дерева
    bt.del();
    cout << endl;
    cout << endl;

    //обратный обход
    bt.showtree1();

    cout << endl;
    cout<<"Кол-во максимумов:";
    cout<<bt.numOfMax();

    return 0;
}
