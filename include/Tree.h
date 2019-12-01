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

        //�����������
        Tree(){
            root = nullptr;
        }

        //����������� �����������
        Tree(Tree& tree){
            root = copyTree(tree.root);
        }

        //���������� ���� - ������
         void add(TreeEl *&t, int n, string s);

         //���������� ����
        void addEl(int n, string s){
                add(root, n, s);
        }

        //����� ������ - ������
        void inorder(TreeEl* &t, int level);

        //����� ������
        void showtree(int level){
                inorder(root, level);
        }

        //�������� ���� - ������
        TreeEl* delNode(TreeEl*& node);

        //�������� ����
        TreeEl* del();

        //������ � �������� ������� - ������
        void revers(TreeEl* &t);

        //����� ������
        void showtree1(){
                revers(root);
        }

        //���������� ���������
        int maxEl(TreeEl*& node);

        //���-�� ���������� - ������
        int maxNum(TreeEl*& node, int key);

        //���-�� ����������
        int numOfMax();

        //�������� ������
        void Destroy(TreeEl*&t);

        //�����������
        TreeEl* copyTree(TreeEl*& t);

        //����������
        ~Tree();
};
#endif // TREE_H
