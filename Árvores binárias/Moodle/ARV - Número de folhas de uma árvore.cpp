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

void contaPreOrdem(treenodeptr arvore, int &n)
{
	if (arvore != NULL)
	{
		if (arvore->esq == NULL && arvore->dir == NULL)
		{
			n++;
		}
		contaPreOrdem(arvore->esq, n);
		contaPreOrdem(arvore->dir, n);
	}
}

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

int contaFolha(treenodeptr arvore)
{
    int n = 0;
    contaPreOrdem(arvore, n);
    return n;
}

int main()
{
    treenodeptr arvore = NULL; // ponteiro para raiz da arvore
    int nos;                     // variável para exibir o num de nós
    int n[100];               // nós de uma arvore
    int i = 0;                 // contador

    cin >> n[i];
    while (n[i] != -1)
    {
        tInsere(arvore, n[i]);
        i++;
        cin >> n[i];
    }

    nos = contaFolha(arvore);

    cout << nos << endl;

    return 0;
}