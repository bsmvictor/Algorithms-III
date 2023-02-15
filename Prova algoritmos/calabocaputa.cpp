#include <iostream>
#include <list>
using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
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

// Realiza um percurso em nível na árvore
void emNivel(treenodeptr t)
{
    treenodeptr n;
    list<treenodeptr> q;
    if (t!=NULL)
    {
        q.push_back(t);
        while (!q.empty())
        {
            n = *q.begin();
            q.pop_front();
            if (n->esq != NULL)
                q.push_back(n->esq);
            if (n->dir != NULL)
                q.push_back(n->dir);
            cout << n->info << " ";
        }
        cout << endl;
    }
}


int main()
{
    treenodeptr arvore = NULL;
    int no;
    int i = 0;

    cin >> no;
    while (no != -1)
    {
        tInsere(arvore, no);
        i++;
        cin >> no;
    }

    // Percurso em nível
    emNivel(arvore);
    
    return 0;
}