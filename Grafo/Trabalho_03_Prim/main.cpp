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

int minKey(vector<int> key, vector<bool> mstSet)
{
    int min = INT32_MAX;
    int indexMin;

    for (int v = 0; v < key.size(); v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            indexMin = v;
        }
    }

    return indexMin;
}

void Prim(Grafo &g, int v)
{
    vector<int> chave(g.vertices.size(), INT32_MAX);
    vector<int> pai(g.vertices.size(), -1);
    vector<bool> naMST(g.vertices.size(), false);

    // Inicie a chave do vértice v como 0 para que ele seja escolhido primeiro.
    chave[v] = 0;

    for (int count = 0; count < g.vertices.size() - 1; count++)
    {
        int u = minKey(chave, naMST);

        naMST[u] = true;

        for (auto x : g.arestas)
        {
            if (x.v1 == u && naMST[x.v2] == false && x.peso < chave[x.v2])
            {
                pai[x.v2] = u;
                chave[x.v2] = x.peso;
            }
            else if (x.v2 == u && naMST[x.v1] == false && x.peso < chave[x.v1])
            {
                pai[x.v1] = u;
                chave[x.v1] = x.peso;
            }
        }
    }

    // Imprimindo a MST
    for (int i = 1; i < g.vertices.size(); i++)
        cout << "A" << i + 1 << ": (" << pai[i] << ", " << i << ") -> Peso: " << chave[i] << endl;
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

    Prim(g, 0);

    cout<<endl<<endl;


    return 0;
}
