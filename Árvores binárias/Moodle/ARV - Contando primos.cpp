#include <iostream>

using namespace std;

struct treenode
{
	int info;
	treenode *esq; // ponteiro esquerdo
	treenode *dir; // ponteiro direito
};

typedef treenode *treenodeptr;

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

void ctp(treenodeptr arvore, int &x)
{
	int y = 0;
	if (arvore != NULL)
	{
		for (int j = 1; j <= arvore->info; j++)
			if (arvore->info % j == 0)
				y++;

		if (y <= 2)
			x++;

		y = 0;
		ctp(arvore->esq, x);
		ctp(arvore->dir, x);
	}
}

int contaPrimos(treenodeptr arvore)
{
	int pri = 0;
	ctp(arvore, pri);
	return pri;
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para raiz da arvore
	float n;				   // numeros a serem inseridos
	int i;					   // quantidade de elementos

	cin >> n;

	while (n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++; //
	}

	cout << contaPrimos(arvore) << " numeros primos" << endl;

	return 0;
}