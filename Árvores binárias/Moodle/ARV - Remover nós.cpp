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

void emOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout << arvore->info << " ";
        emOrdem(arvore->dir);
    }
}

treenodeptr tMenor(treenodeptr &raiz)
{
    treenodeptr t;
    t = raiz;
    if (t->esq == NULL) // encontrou o menor valor
    {
        raiz = raiz->dir;
        return t;
    }
    else // continua a busca na sub ´arvore esquerda
        return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x)
{
    treenodeptr p;
    if (raiz == NULL) // ´arvore vazia
        return 1;
    if (x == raiz->info)
    {
        p = raiz;
        if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
            raiz = raiz->dir;
        else if (raiz->dir == NULL) // a raiz n~ao tem filho direito
            raiz = raiz->esq;
        else // a raiz tem ambos os filhos
        {
            p = tMenor(raiz->dir);
            raiz->info = p->info;
        }
        delete p;
        return 0;
    }
    else if (x < raiz->info)
        return tRemove(raiz->esq, x);
    else
        return tRemove(raiz->dir, x);
}

void tDestruir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

int main()
{
    int n; // variável auxiliar para leitura de dados
    int j = 0;
    int x;                     // nó a ser removido
    treenodeptr arvore = NULL; // armazena os números

    cin >> n;

    while (n != 0)
    {
        j++;
        tInsere(arvore, n);
        cin >> n;
    }

    cin >> x;

    for (int i = 0; i < j; i++)
    {
        tRemove(arvore, x);
    }

    emOrdem(arvore);
    tDestruir(arvore);
    //OBS: nao da pra implementar a função tDestruir usando os percursos em-ordem e pos-ordem.

    return 0;
}