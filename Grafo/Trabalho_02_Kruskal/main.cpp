#include<iostream>
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

bool ComparaAresta(Aresta a1, Aresta a2)
{
    return a1.peso < a2.peso;
}

int Find(int i, vector<int> &pai)
{
    //vai ate achar
    if (i == pai[i])
        return i;
    return Find(pai[i], pai);
}

void Union1(int i, int j, vector<int> &pai)
{
    pai[i] = j;
}

void Kruskal(Grafo &g)
{
    sort(g.arestas.begin(), g.arestas.end(), ComparaAresta);

    vector<int> pai(g.vertices.size());
    for (int i = 0; i < g.vertices.size(); i++)
        pai[i] = i;

    vector<Aresta> resultado;


    for (int i = 0; i < g.arestas.size(); i++)
    {
        int u = g.arestas[i].v1;
        int v = g.arestas[i].v2;

        int set_u = Find(u, pai);
        int set_v = Find(v, pai);

        if (set_u != set_v)
        {
            resultado.push_back(g.arestas[i]);
            Union1(set_u, set_v, pai);
        }
    }

    // Imprime as arestas do MST
    for (int i = 0; i < resultado.size(); i++)
    {
        cout << "A"<<i+1<<": ("<< resultado[i].v1 << ", " << resultado[i].v2 << ") -> Peso: " << resultado[i].peso << endl;
    }

}

int main()
{
    Grafo g;
    for (int i = 0; i < 7; i++)
        g.vertices.push_back(i);
           
   //           V1 ,V2 ,Peso
    Aresta a1 = {0, 1, 2};
    Aresta a2 = {0, 3, 7};
    Aresta a3 = {0, 6, 2};
    Aresta a4 = {1, 6, 5};
    Aresta a5 = {1, 2, 1};
    Aresta a6 = {1, 3, 4};
    Aresta a7 = {1, 4, 3};
    Aresta a8 = {2, 6, 4};
    Aresta a9 = {2, 4, 4};
    Aresta a10 = {3, 5, 5};
    Aresta a11 = {3, 4, 1};
    Aresta a12 = {4, 5, 7};


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

    Kruskal(g);

    return 0;
    
}