#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct TreeEl
{
    TreeEl *left;
    TreeEl *right, *parent;
    int num;
    string text;
    TreeEl(int n = 0, string s = "", TreeEl* l = 0, TreeEl* r = 0):num(n), left(l), right(r), text(s){}
};

class Tree
{
        TreeEl *root;

public:

        //конструктор
        Tree(){
            root = nullptr;
        }

        //конструктор копирования
        Tree(Tree& tree){
            root = copyTree(tree.root);
        }

        //добавление узла - основа
         void add(TreeEl *&t, int n, string s);

         //добавление узла
        void addEl(int n, string s){
                add(root, n, s);
        }

        //вывод дерева - основа
        void inorder(TreeEl* &t, int level);

        //вывод дерева
        void showtree(int level){
                inorder(root, level);
        }

        //удаление узла - основа
        TreeEl* delNode(TreeEl*& node);

        //удаление узла
        TreeEl* del();

        //проход в обратном порядке - основа
        void revers(TreeEl* &t);

        //вывод дерева
        void showtree1(){
                revers(root);
        }

        //нахождение максимума
        int maxEl(TreeEl*& node);

        //кол-во максимумов - основа
        int maxNum(TreeEl*& node, int key);

        //кол-во максимумов
        int numOfMax();

        //удаление дерева
        void Destroy(TreeEl*&t);

        //копирование
        TreeEl* copyTree(TreeEl*& t);

        //деструктор
        ~Tree();
};
#endif // TREE_H
