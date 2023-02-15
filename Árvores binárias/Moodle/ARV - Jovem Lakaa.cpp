#include <iostream>

using namespace std;

struct treenode
{
    int info;
    treenode *esq; // ponteiro esquerdo
    treenode *dir; // ponteiro direito
};

typedef treenode *treenodeptr;

// caminho para preOrdem
int cam;
int cam2;

// caminho para emOrdem
int Cam;
int Cam2;

// caminho para posOrdem
int CAM;
int CAM2;

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

void preOrdem(int y, treenodeptr arvore)
{
    if (arvore != NULL)
    {
        cam++;
        if (arvore->info == y)
            cam2 = cam;
        preOrdem(y, arvore->esq);
        preOrdem(y, arvore->dir);
    }
}

void emOrdem(int y, treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdem(y, arvore->esq);
        Cam++;
        if (arvore->info == y)
            Cam2 = Cam;
        emOrdem(y, arvore->dir);
    }
}

void posOrdem(int y, treenodeptr arvore)
{
    if (arvore != NULL)
    {

        posOrdem(y, arvore->esq);
        posOrdem(y, arvore->dir);
        CAM++;
        if (arvore->info == y)
        {
            CAM2 = CAM;
        }
    }
}

int main()
{
    treenodeptr arvore = NULL;
    int n = 0; // números
    int cidade;

    cin >> n;

    while (n != -1)
    {
        tInsere(arvore, n);
        cin >> n;
    }

    cin >> cidade;

    emOrdem(cidade, arvore);
    posOrdem(cidade, arvore);
    preOrdem(cidade, arvore);

    if (cam2 <= CAM2 && cam2 <= Cam2)
    {
        cout << "Pre" << endl;
    }
    else if (CAM2 <= cam2 && CAM2 <= Cam2)
    {
        cout << "Pos" << endl;
    }
    else
        cout << "Em" << endl;

    return 0;
}