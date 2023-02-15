#include <iostream>
#include <iomanip>

using namespace std;

struct alunos
{
    int nota1, nota2, nota3, nota4;
    float media;
};

int main()
{
    alunos *notas = NULL; // ponteiro para o vetor

    // alocando memoria
    notas = new alunos;

    // inserindo notas dos alunos
    cin >> notas->nota1 >> notas->nota2 >> notas->nota3 >> notas->nota4;

    // calculando a Media
    notas->media = (notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4) / 4.0;

    // exibindo media dos Alunos
    cout << fixed << setprecision(2);
    cout << notas->media;

    // liberando memoria
    delete[] notas;

    return 0;
}