#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Aresta
{
public:
    int v1, v2, peso;
};

class Grafo
{
public:
    vector<int> vertices;
    vector<Aresta> arestas;
};

void BellmanFord(Grafo &g, int v)
{
    vector<int> dist(g.vertices.size(), INT32_MAX);
    dist[v] = 0;


    for (int i = 1; i <= g.vertices.size() - 1; i++)
    {
        for (auto x : g.arestas)
        {
            int u = x.v1;
            int v = x.v2;
            int peso = x.peso;
            if (dist[u] != INT32_MAX && dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
            }
        }
    }

    //loop pra verificar se não há ciclos negativos 
    for (auto x : g.arestas)
    {
        int u = x.v1;
        int v = x.v2;
        int peso = x.peso;
        if (dist[u] != INT32_MAX && dist[u] + peso < dist[v])
            cout << "O grafo contem um ciclo de peso negativo" << endl;
    }

    // Mostrando a MST através das distancias mínimas do vértice de partida até cada vértice restante do grafo
    for (int i = 0; i < g.vertices.size(); i++)
        cout << "Distancia do vertice " << v << " ao vertice " << i << ": " << dist[i] << endl;
}

int main()
{
    Grafo g;
    for (int i = 1; i <= 7; i++)
        g.vertices.push_back(i);

    //           V1 ,V2 ,Peso
    Aresta a1 = {0, 1, 1};
    Aresta a2 = {0, 3, 4};
    Aresta a3 = {1, 3, 6};
    Aresta a4 = {1, 4, 4};
    Aresta a5 = {1, 2, 2};
    Aresta a6 = {2, 4, 5};
    Aresta a7 = {2, 5, 6};
    Aresta a8 = {3, 4, 3};
    Aresta a9 = {3, 6, 4};
    Aresta a10 = {4, 5, 8};
    Aresta a11 = {4, 6, 7};
    Aresta a12 = {5, 6, 3};

    g.arestas.push_back(a1);
    g.arestas.push_back(a2);
    g.arestas.push_back(a3);
    g.arestas.push_back(a4);
    g.arestas.push_back(a5);
    g.arestas.push_back(a6);
    g.arestas.push_back(a7);
    g.arestas.push_back(a8);
    g.arestas.push_back(a9);
    g.arestas.push_back(a10);
    g.arestas.push_back(a11);
    g.arestas.push_back(a12);

    cout<<endl<<endl;

    BellmanFord(g, 0);

    cout<<endl<<endl;

    return 0;
}
