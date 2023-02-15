#include <iostream>  // Entrada e sa�da
#include <climits>   // INT_MAX
#include <algorithm> // next_permutation
using namespace std;

int main()
{
    
    int custo[100][100]; // 100 -> numero maximo de locais de entrega
                         // custo[i][j] = custo de ir da entrega 'i' para a entrega 'j'
    int n;               // numero de entregas
    int entregadores; // numero de entregadores
    int cidade_inicial;//supermercado

    cout << "Entre com o numero de locais " << endl;
    cin >> n;

    //preenchendo o grafo
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j < n; j++)
        {
            cout << "Entre com o custo de ida do lugar " << i << " para o lugar" << j << endl;
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }
    cout << "Entre com o lugar de entrega inicial " << endl;
    cin >> cidade_inicial;

    //preenchendo o grafo com a posição dos entregadores
    cin >> entregadores;
    for (int i = 0; i < entregadores; i++)
        for (int j = i + 1; j < entregadores; j++)
        {
            cout << "Entre com o custo do entregador ir do lugar " << i << "para o lugar " << j << endl;
            cin >> custo_posicao[i][j];
            custo_posicao[i][j] = custo_posicao[i][j];
        }


    int v[100];        // vetor com as cidades a serem permutadas
    int p;             // var. auxiliar
    int menor_custo;   // menor custo da viagem
    int custo_caminho; // custo do caminho

    // colocando as cidades que serao permutadas no vetor (todas exceto a inicial)
    p = 0;
    for (int i = 0; i < n; i++)
        if (i != cidade_inicial)
        {
            v[p] = i;
        }

           p++;
     // forca bruta
    menor_custo = INT_MAX; // inicializo o custo com infinito
    do
    {
        custo_caminho = custo[cidade_inicial][v[0]]; // custo da cidade inicial -> v[0]

        for (int i = 0; i < n - 2; i++) // somar custo de v[0]->v[1]->v[2]...v[n-3]->v[n-2]
            custo_caminho += custo[v[i]][v[i + 1]];

        custo_caminho += custo[v[n - 2]][cidade_inicial]; // custo v[n-2] -> cidade inicial

        menor_custo = min(menor_custo, custo_caminho);
    } while (next_permutation(v, v + (n - 1))); // n-1 = numero de cidades a serem permutadas
    // obs.: para fazer todas as permutacoes, o vetor deve estar ordenado no comeco

    cout << "Menor custo = " << menor_custo << endl;

    return 0;
}

