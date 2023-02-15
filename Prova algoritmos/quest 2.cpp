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
    else if (x > p->info) // insere na subarvore direita
        tInsere(p->dir, x);
}

void posOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        cout << arvore->info << " ";
    }
}

treenodeptr tPesq(treenodeptr p, int x)
{
    if (p == NULL) // elemento não encontrado
        return NULL;

    else if (x == p->info) // elemento encontrado na raiz
        return p;

    else if (x < p->info) // procura na sub ́arvore esquerda
        return tPesq(p->esq, x);

    else // procura na sub ́arvore direita
        return tPesq(p->dir, x);
}

int main()
{
    int x = 0; // variavel auxiliar para leitura de dados
    treenodeptr p = NULL;
    treenodeptr arvore = NULL; // armazena os numeros

    cin >> x;

    while (x != -1)
    {
        tInsere(arvore, x);
        cin >> x;
    }

    posOrdem(arvore);

    return 0;
}