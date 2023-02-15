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

// Pesquisar elementos na arvore
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
    treenodeptr arvore = NULL; // ponteiro para raiz da arvore
    treenodeptr p = NULL;      // armazena os numeros
    int x = 0;                 // variavel auxiliar para leitura de dados
    int N;                     // total de numeros q serão entrados
    int num;                     // numeros inseridos na arvore

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        tInsere(arvore, num);
    }
    cin >> x;

    // Buscando x
    p = tPesq(arvore, x);

    // Saida
    if (p == 0)
        cout << "Nao encontrado" << endl;
    else
        cout << "Encontrado" << endl;

    return 0;
}
