#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct itens
{
    int valor; // valor item
    int peso;  // peso item
};

// função de ordenação
void ordenado(int dist[], int tam)
{
    int i, j, aux, menor;

    for (i = 0; i < (tam - 1); i++)
    {
        menor = i;
        for (j = (i + 1); j < tam; j++)
        {
            if (dist[j] < dist[menor])
                menor = j;
        }
        if (dist[i] != dist[menor])
        {
            aux = dist[i];
            dist[i] = dist[menor];
            dist[menor] = aux;
        }
    }
}

int main()
{

    itens vitens[100];     // vetor para valor e peso dos itens
    int analise[100][100]; // calculo do valor e peso dos itens em relação a capacidade mochila "PD"
    int caminho[100][100]; // caminho
    int custo[100][100];   // custo das compras
    int pcompra[100];      // peso das compras
    int distancia[100];    // distancia das entregas
    int tempo[100];        // tempo das entregas
    int entregador[100];   // numero de entregadores
    int tfinal;            // tempo final das entregas
    int destinofinal;      // destino final do entregador
    int maior;             // comparar tempos de entrega
    int capacidade;        // capacidade max da mochila
    int supermercado;      // local de inicio, onde fica o supermercado
    int destino;           // destino das entregas
    int lugares;           // lugares das entregas
    int i, j, aux, aux2;   // aux e contadores

    cout << "Entre com o numero de entregadores: ";
    cin >> aux2; // aux para numero de entregadores

    for (i = 0; i < aux2; i++)
    {
        cout << "\ndistancia do entregador " << i + 1 << " para o mercado: ";
        cin >> distancia[i];
        entregador[distancia[i]] = i + 1;
    }

    // chamando a função
    ordenado(distancia, aux2);

    cout << "\nNumero de entregas a serem feitas: ";
    cin >> lugares;
    lugares++;

    cout << "\ncapacidade maxima da mochila de cada entregador: ";
    cin >> capacidade;

    // numero de entregas
    for (i = 1; i < lugares - 1; i++)
    {
        cout << "\nCompra: ";
        cin >> aux;

        cout << "Peso: ";
        cin >> pcompra[aux];
    }

    cout << "\nLocal do supermercado: ";
    cin >> supermercado;

    // numero de lugares
    for (i = 1; i < lugares; i++)
        for (j = i + 1; j < lugares; j++)
        {
            cout << "\nDistancia entre os locais de entrega " << i << " e " << j << ": ";
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }

    cout << endl;

    cout << "Caminho das viagens:" << endl;

    // caminho das viagens
    for (i = 1; i < lugares; i++)
        if (i != supermercado)
        {
            destino = i;
            int menorCusto = 0; // menor custo
            int custoAtual;     // custo atual
            int lugarAtual;     // lugar atual
            int proximo;        // proximo lugar
            int aux3, aux4;     // auxiliares
            bool visitado[100]; // local visitado ou nao

            // nenhum lugar ainda visitado
            for (aux3 = 0; aux3 < lugares; aux3++)
                visitado[aux3] = false;

            lugarAtual = supermercado;
            cout << endl;
            cout << "\t" << lugarAtual << " - ";

            // lugar mais proximo (guloso)
            for (int i = 1; i < lugares - 1; i++)
            {
                visitado[lugarAtual] = true; //

                custoAtual = INT_MAX;

                for (aux4 = 1; aux4 < lugares; aux4++)
                {
                    if (!visitado[aux4] && custoAtual > custo[lugarAtual][aux4])
                    {
                        proximo = aux4;
                        custoAtual = custo[lugarAtual][aux4];
                    }
                }
                if (lugarAtual == destino)
                    break;
                else
                {
                    menorCusto += custoAtual;
                    lugarAtual = proximo;
                }
                cout << lugarAtual << " - ";
            }
            tempo[i] = menorCusto;
            cout << "para a viagem " << lugarAtual << endl;
        }

    for (i = 0; i < lugares; i++)
    {
        if (i != supermercado)
        {
            vitens[i].valor = tempo[i];  //
            vitens[i].peso = pcompra[i]; //
        }
    }

    // Caso base para o problema da mochila
    for (int aux5 = 0; aux5 <= capacidade; aux5++)
        analise[lugares][aux5] = 0;

    for (int aux6 = 0; aux6 <= lugares; aux6++)
        analise[aux6][0] = 0; // mochila = 0

    for (int aux7 = 0; aux7 < aux2; aux7++)
    {
        vitens[0].valor = 0;            //
        vitens[supermercado].valor = 0; //

        // Caso geral para o problema da mochila
        for (int aux8 = lugares - 1; aux8 >= 0; aux8--)
            for (int aux9 = 1; aux9 <= capacidade; aux9++)
            {
                int valido, nvalido;

                nvalido = analise[aux8 + 1][aux9];

                if (aux9 >= vitens[aux8].peso)
                    valido = analise[aux8 + 1][aux9 - vitens[aux8].peso] + vitens[aux8].valor;

                else
                    valido = 0;

                if (valido > nvalido)
                {
                    analise[aux8][aux9] = valido;
                    caminho[aux8][aux9] = 1;
                }

                else
                {
                    analise[aux8][aux9] = nvalido;
                    caminho[aux8][aux9] = 0;
                }
            }

        // Recuperando o caminho
        i = 0;
        j = capacidade;
        maior = 0;
        tfinal = distancia[aux7];

        cout << "\nEntregador " << entregador[distancia[aux7]] << endl;

        cout << endl;

        // analise de todos os itens
        while (i != lugares)
        {
            if (caminho[i][j] == 0)
                i++;

            else if (caminho[i][j] == 1)
            {
                if (maior < vitens[i].valor)
                {
                    maior = vitens[i].valor;
                    destinofinal = i;
                }

                cout << "\tItem: " << i << endl;
                cout << "\tPeso: " << vitens[i].peso;

                j -= vitens[i].peso;
                vitens[i].valor = 0;
                i++;
                cout << endl;
            }
        }

        // exibindo resultados
        if (maior > 0)
            cout << "\tTempo total: " << tfinal + maior << endl;

        else
            cout << "\tNao levou nada: " << endl;
    }

    return 0;
}