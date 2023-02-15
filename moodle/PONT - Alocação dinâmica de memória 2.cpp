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
    int i;                // contador
    int n;                // tamanho do vetor
    float media;          // media dos Alunos

    // inserindo tamanho do vetor
    cin >> n;

    // alocando memoria
    notas = new alunos;

    // liberando memoria
    delete[] notas;

    return 0;
}