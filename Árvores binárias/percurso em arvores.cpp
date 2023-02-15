#include <iostream>

using namespace std;

struct treenode
{
    int info;
    treenode *esq; // ponteiro esquerdo
    treenode *dir; // ponteiro direito
};

typedef treenode *treenodeptr; // um ponteiro para outro, são sinônimos

// Inserir elementos na arvore
void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
}

void contaPreOrdem(treenodeptr arvore, int &n)
{
    if (arvore != NULL)
    {
        n++;
        contaPreOrdem(arvore->esq, n);
        contaPreOrdem(arvore->dir, n);
    }
}

/*
void emOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout << arvore->info << endl;
        emOrdem(arvore->dir);
    }
}

void posOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        cout << arvore->info << endl;
    }
}

void preOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        cout << arvore->info << endl;
        preOrdem(arvore->esq);
        preOrdem(arvore->dir);
    }
}

*/


contaNos(treenodeptr arvore) // utilizável para somar nós, tirar media de nós...
{
    int n = 0; // conta os nós
    contaPreOrdem(arvore, n);
    return n;
}

int main()
{
    treenodeptr arvore = NULL; // ponteiro para raiz da arvore
    int n;                     // numero de elementos inseridos

    tInsere(arvore, 12);
    tInsere(arvore, 9);
    tInsere(arvore, 20);
    tInsere(arvore, 7);
    tInsere(arvore, 10);

    n = contaNos(arvore);
    cout << n << " elementos inseridos" << endl;

    /*
        cout <<  "Pre-Ordem:" << endl;
        preOrdem(arvore);


        cout << "Pre-Ordem:" << endl;
        emOrdem(arvore);

        cout << "Pre-Ordem:" << endl;
        posOrdem(arvore);
    */
    return 0;
}
