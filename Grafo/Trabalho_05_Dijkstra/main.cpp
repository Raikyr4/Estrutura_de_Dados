#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// class Aresta
// {
// public:
//     int v1, v2, peso;
// };


// Minha ADJLIST vira minha classe aresta

class Grafo
{
public:
    vector<int> vertices;
    vector<vector<pair<int, int>>> adjlist;

    void addAresta(int v1, int v2, int peso)
    {
        adjlist[v1].push_back({v2, peso});
        adjlist[v2].push_back({v1, peso}); // Se o grafo for não direcionado
    }
};

int Dijkstra(Grafo &g, int ini, int fim)
{
    // Inicializa todas as distâncias com infinito
    vector<int> dist(g.vertices.size(), INT_MAX);
    dist[ini] = 0; // A distância do vértice inicial para ele mesmo é 0

    // Cria uma fila de prioridade onde o vértice com menor distância tem maior prioridade
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, ini}); // Insere o vértice inicial na fila com distância 0

    // Enquanto a fila não estiver vazia
    while (!Q.empty())
    {
        // Remove o vértice com a menor distância da fila
        pair<int, int> u = Q.top();
        Q.pop();

        // Para cada vértice V adjacente ao vértice u
        for (auto &V : g.adjlist[u.second])
        {
            // Se a distância do vértice u + o peso da aresta UV for menor que a distância atual do vértice V
            if (dist[u.second] + V.second < dist[V.first])
            {
                // Atualiza a distância do vértice V
                dist[V.first] = dist[u.second] + V.second;
                // Insere o vértice V na fila com a nova distância
                Q.push({dist[V.first], V.first});
            }
        }
    }

    // Retorna a distância mínima do vértice inicial para o vértice final
    return dist[fim];
}


int main()
{
    Grafo g;
    g.adjlist.resize(7);
    for (int i = 0; i < 7; i++)
        g.vertices.push_back(i);

    //           V1 ,V2 ,Peso
    g.addAresta(0, 1, 1);
    g.addAresta(0, 3, 4);
    g.addAresta(1, 3, 6);
    g.addAresta(1, 4, 4);
    g.addAresta(1, 2, 2);
    g.addAresta(2, 4, 5);
    g.addAresta(2, 5, 6);
    g.addAresta(3, 4, 3);
    g.addAresta(3, 6, 4);
    g.addAresta(4, 5, 8);
    g.addAresta(4, 6, 7);
    g.addAresta(5, 6, 3);

    cout << endl
         << endl;

    int dist = Dijkstra(g, 3, 6);
    cout << "Distancia minima do vertice 0 para o vertice 6 eh " << dist << endl;

    cout << endl
         << endl;

    return 0;
}
