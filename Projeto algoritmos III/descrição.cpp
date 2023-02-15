#include <iostream>
#include <list>
#include <climits>

using namespace std;
struct no
{
    int v;       // vertice de destino
    int p;       // peso da aresta
    bool status; // status
};

// função de criar arestas
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no aux; // var aux para inserir arestas no grafo
    aux.v = v;
    aux.p = p;

    adj[u].push_back(aux);

    if (orientado == 0)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

void dijkstra(list<no> adj[], int nVertices, int start, int end)
{
    bool intree[100];
    long long int distance[100];
    int parent[100];
    int v;
    list<no>::iterator p;
    no res[100];
    list<int> resposta;
    list<int>::iterator r;

    long long int dist;
    int destino;
    int weight;

    int u = 0;

    for (u = 0; u < nVertices; u++)
    {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        for (p = adj[v].begin(); p != adj[v].end(); p++)
        {
            destino = p->v;
            weight = p->p;

            if (distance[destino] > weight + distance[v])
            {
                distance[destino] = weight + distance[v];
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;

        for (u = 0; u < nVertices; u++)

        {
            if (intree[u] == false && dist > distance[u])
            {
                if (res[u].status == false || res[u].p > distance[u])
                {
                    res[u].v = parent[u];
                    res[u].p = distance[u];
                    res[u].status = true;
                }

                dist = distance[u];
                v = u;
            }
        }
    }

    v = end;
    resposta.push_front(v);

    while (v != start)
    {
        v = res[v].v;
        resposta.push_front(v);
    }

    cout << "Menor caminho: ";
    for (r = resposta.begin(); r != resposta.end(); r++)
    {
        cout << *r << " ";
    }
    cout << "\nCusto: " << distance[end] << endl;
}

int main()
{
    list<no> adj[10]; // lista de adjacencia
    int nVertices;    // numero de vertice do grafo
    int orientado;    // 1:orientado, 0:nao orientado
    int iVertice;     // vertice inicial da arvore
    int u, v;         // origem e destino da aresta
    int peso;         // peso da aresta
    int fVertice;     // vertice final
    int i;

    while(i = 0; i < nVertices; i++)
    {
        cout << "numero de cidades" << endl;
        cin >> nVertices;

        cout << "coloca 1 pq possui peso" << endl;
        cin >> orientado;

        cout << "cidade inicial" << endl;
        cin >> iVertice;

        cout << "cidade final" << endl;
        cin >> fVertice;

        cout << "da cidade " << endl;
        cin >> u;

        cout << "para cidade" << endl;
        cin >> v;

        cout << "peso entre essas cidades" << endl;
        cin >> peso;
    }

    // inserindo arestas no grafo
    while (u != -1 && v != -1 && peso != -1)
    {
        cria_aresta(adj, u, v, peso, orientado);

        cin >> u >> v >> peso;
    }

    // chamando funcao dijkstra
    dijkstra(adj, nVertices, iVertice, fVertice);

    return 0;
}
