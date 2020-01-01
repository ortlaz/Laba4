#include "Tree.h"

//Прямой обход
void Tree::inorder(TreeEl* &t, int level)
{
    if ( t ) {

        //движение по правой ветке
        inorder( t->right, level+1);

        for(int i=0;i<level;i++) cout<<"\t";

        //посещение узла
        cout << t->num <<"-"<<t->text<<endl;

        //движение по левой ветке
        inorder( t->left, level+1);
     }
    else return;
}

//Добавление
void Tree::add(TreeEl *&t, int n, string s){

    //если корня дерева не существует
    if(t == NULL){

        //создать корень
        t = new TreeEl(n,s);
    }
    else{
        if(n < t->num){

            //левый потомок
            add(t->left, n,s);
        }
        else{

            //правый потомок
            add(t->right, n,s);
        }
    }
}

//Удаление элемента
TreeEl* Tree::delNode(TreeEl*& node){
    //если нет корня
	if(node == NULL)
		return NULL;

    //если значение в корне совпадает с искомым
    if(node->num == 0){

        //если у корня нет потомков
        if(node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }

        //если нет левого потомка
        if(node->right == NULL && node->left!=NULL){
            TreeEl* temp = node->left; //ставим на место корня правого потомка
            free(node);
            return temp;
        }

        //аналогично при отсутствии правого потомка
        if(node->left == NULL && node->right!=NULL){
            TreeEl* temp = node->right;
            free(node);
            return temp;
        }

        //движемся по правой ветке
        node->right = delNode(node->right);
        return node;
    }

    //если значение в корне больше искомого
    if(0<node->num){
        node->left = delNode(node->left); //идем по левой ветке
    }

    //если значение в корне меньше искомого
    if(0>node->num){
        node->right = delNode(node->right); //идем по правой ветке
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

//Обратный обход
void Tree::revers(TreeEl* &t)
{
    if ( t != NULL ) {

        //движение по левой ветке
        revers( t->left );

        //движение по правой ветке
        revers( t->right );

        //посещение узла
        cout << t->num <<"\t"<<t->text<< " | ";
     }
    else return;
}

//нахождение максимального узла
int Tree::maxEl(TreeEl*& node) {

    if (node == NULL) {
        return 0;
    }
    int max_l = max(maxEl(node->left), node->num);
    int max_r = max(maxEl(node->right), node->num);
    return max(max_l, max_r);
}

//кол-во максимальных узлов
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

//деструктор
Tree::~Tree(){
    Destroy(root);
}

//удаление дерева
void Tree::Destroy(TreeEl*& t){
    delete t;
}

//копирование
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
