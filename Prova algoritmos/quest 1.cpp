/*construa uma arvore com percurso em nível que
calcule por meio de uma função a media da arvore*/
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};

typedef treenode *treenodeptr;

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

// Realiza um percurso em nível na árvore
void emNivel(treenodeptr t)
{
    treenodeptr n;
    list<treenodeptr> q;
    if (t != NULL)
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
            // cout << n->info << " "; //exibir os nos
        }
        cout << endl;
    }
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
    treenodeptr arvore = NULL;
    int No[100];
    int i = 0;

    cin >>No[i];
    while (No[i] != -1)
    {
        tInsere(arvore, No[i]);
        i++;
        cin >> No[i];
    }

    // Percurso em nível
    emNivel(arvore);

    // Media
    average(arvore);

    cout << fixed << setprecision(2);
    cout << "Media: " << (sum / n) * 1.0 << endl;

    return 0;
}