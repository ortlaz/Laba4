#include "Tree.h"

//������ �����
void Tree::inorder(TreeEl* &t, int level)
{
    if ( t ) {

        //�������� �� ������ �����
        inorder( t->right, level+1);

        for(int i=0;i<level;i++) cout<<"\t";

        //��������� ����
        cout << t->num <<"-"<<t->text<<endl;

        //�������� �� ����� �����
        inorder( t->left, level+1);
     }
    else return;
}

//����������
void Tree::add(TreeEl *&t, int n, string s){

    //���� ����� ������ �� ����������
    if(t == NULL){

        //������� ������
        t = new TreeEl(n,s);
    }
    else{
        if(n < t->num){

            //����� �������
            add(t->left, n,s);
        }
        else{

            //������ �������
            add(t->right, n,s);
        }
    }
}

//�������� ��������
TreeEl* Tree::delNode(TreeEl*& node){
    //���� ��� �����
	if(node == NULL)
		return NULL;

    //���� �������� � ����� ��������� � �������
    if(node->num == 0){

        //���� � ����� ��� ��������
        if(node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }

        //���� ��� ������ �������
        if(node->right == NULL && node->left!=NULL){
            TreeEl* temp = node->left; //������ �� ����� ����� ������� �������
            free(node);
            return temp;
        }

        //���������� ��� ���������� ������� �������
        if(node->left == NULL && node->right!=NULL){
            TreeEl* temp = node->right;
            free(node);
            return temp;
        }

        //�������� �� ������ �����
        node->right = delNode(node->right);
        return node;
    }

    //���� �������� � ����� ������ ��������
    if(0<node->num){
        node->left = delNode(node->left); //���� �� ����� �����
    }

    //���� �������� � ����� ������ ��������
    if(0>node->num){
        node->right = delNode(node->right); //���� �� ������ �����
        return node;
    }
    return node;
}

TreeEl* Tree::del(){
    int k = maxNum(root, 0);
    while (k){
        delNode(root);
        k--;
    }
}

//�������� �����
void Tree::revers(TreeEl* &t)
{
    if ( t != NULL ) {

        //�������� �� ����� �����
        revers( t->left );

        //�������� �� ������ �����
        revers( t->right );

        //��������� ����
        cout << t->num <<"\t"<<t->text<< " | ";
     }
    else return;
}

//���������� ������������� ����
int Tree::maxEl(TreeEl*& node) {

    if (node == NULL) {
        return 0;
    }
    int max_l = max(maxEl(node->left), node->num);
    int max_r = max(maxEl(node->right), node->num);
    return max(max_l, max_r);
}

//���-�� ������������ �����
int Tree::maxNum(TreeEl*& node, int key) {

    if (node == NULL)
        return 0;

    if (key < node->num) {
        return maxNum(node->left, key);

    } else if (key > node->num) {
        return maxNum(node->right, key);

    } else {
        return 1 + maxNum(node->right, key);
    }
}

int Tree::numOfMax(){
    return maxNum(root, maxEl(root));
}

//����������
Tree::~Tree(){
    Destroy(root);
}

//�������� ������
void Tree::Destroy(TreeEl*& t){
    delete t;
}

//�����������
TreeEl* Tree::copyTree(TreeEl*& t){
    TreeEl *newlptr, *newrptr, *newnode;

    if(t==NULL)
        return NULL;

    if(t->left!=NULL)
        newlptr=copyTree(t->left);
    else
        newlptr=NULL;

    if(t->right!=NULL)
        newrptr=copyTree(t->right);
    else
        newrptr=NULL;

    newnode=new TreeEl(t->num, t->text, newlptr, newrptr);

    return newnode;
}
