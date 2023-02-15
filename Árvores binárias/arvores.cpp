#include <iostream>

using namespace std;

struct treenode
{
    int info;
    treenode *esq; // ponteiro esquerdo
    treenode *dir; // ponteiro direito
};

typedef treenode *treenodeptr; // um ponteiro para outro, são sinônimos

int main()
{
    treenode *arvore = NULL; // ponteiro para raiz da arvore
    int x;

    x = 14;
    arvore = new treenode;
    arvore->info = x;
    arvore->esq = NULL; //
    arvore->dir = NULL; //

    x = 15;
    arvore->dir = new treenode;
    arvore->dir->info = x;
    arvore->dir->esq = NULL; //
    arvore->dir->dir = NULL; //

    x = 4;
    arvore->esq = new treenode;
    arvore->esq->info = x;
    arvore->esq->esq = NULL; //
    arvore->esq->dir = NULL; //

    cout << arvore->info << endl;
    cout << arvore->esq->info << endl;
    cout << arvore->dir->info << endl;

    return 0;
}