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

// função que ordena e analisa maior e menor elemento de uma arv
void mnpreOrdem(treenodeptr arvore, int &m, int &n)
{
    // m = maior, n = menor
    if (arvore != NULL)
    {
        // compara se eh maior
        if (arvore->info > m)
            m = arvore->info;

        // compara se eh menor
        if (arvore->info < n)
            n = arvore->info;

        // cout << arvore->info << endl;
        mnpreOrdem(arvore->esq,m,n);
        mnpreOrdem(arvore->dir,m,n);
    }
}

int main()
{
    treenodeptr p = NULL;
    treenodeptr arvore = NULL; // armazena os numeros
    int x = 0;                 // variável auxiliar para leitura de dados (no)
    int m = -10000;            // maior
    int n = 10000;             // menor

    //inserindo nos na arvore
    cin >> x;
    while (x != -1)
    {
        tInsere(arvore, x);
        cin >> x;
    }

    //chamando a função
    mnpreOrdem(arvore,m,n);

    //exibindo elementos
    cout << n << " e " << m << endl;

    return 0;
}