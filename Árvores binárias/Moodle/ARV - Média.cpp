#include <iostream>
#include <iomanip>

using namespace std;

struct treenode
{
    int info;
    treenode *esq; // ponteiro esquerdo
    treenode *dir; // ponteiro direito
};

typedef treenode *treenodeptr; // um ponteiro para outro, são sinônimos

// variáveis globais para realizar o calculo da media
float sum = 0;
int n = 0;

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

void average(treenodeptr arvore)
{

    if (arvore != NULL)
    {
        average(arvore->dir);
        sum += arvore->info;
        n++;
        average(arvore->esq);
    }
}

int main()
{
    int x = 0;
    treenodeptr arvore = NULL; // ponteiro para raiz da arvore
    treenodeptr p = NULL;      // armazena os numeros

    cin >> x;

    while (x != -1)
    {
        tInsere(arvore, x);
        cin >> x;
    }

    average(arvore);

    cout << fixed << setprecision(2);
    cout << "Media: " << (sum / n) * 1.0 << endl;

    return 0;
}