#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Grafo
{
public:
    int V;
    map<int, set<int>> adj;
    int mat[100][100] = {{0}};

public:
    Grafo(int V)
    {
        this->V = V;
        for (int i = 1; i <= V; i++)
        {
            set<int> x;
            adj.insert({i, x});
        }
    }

    void AdicionarAresta(int n, int m)
    {
        adj[n].insert(m);
        adj[m].insert(n);

        mat[n][m] = 1;
        mat[m][n] = 1;
    }

    static void ImprimeGrafo(Grafo g)
    {
        cout << endl
             << "Grafo : " << endl;
        for (auto it : g.adj)
        {
            cout << '[' << it.first << "] -> ";
            for (auto it2 : it.second)
            {
                cout << it2 << ", ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

    static void ImprimeGrafoComplementar(Grafo g)
    {
        map<int, set<int>>::iterator it = g.adj.begin();
        map<int, set<int>> complentar;

        for (int i = 0; i < g.V; i++, it++)
        {
            for (int h = 0; h < g.V; h++)
            {
                if (g.mat[it->first][h] == 0 && h != it->first && h != 0)
                {
                    complentar[it->first].insert(h);
                    complentar[h].insert(it->first);
                }
            }
        }

        cout << endl
             << "Grafo Complementar : " << endl;
        for (auto it : complentar)
        {
            cout << '[' << it.first << "] -> ";
            for (auto it2 : it.second)
            {
                cout << it2 << ", ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

    bool DFS(int u, int pai, vector<bool> &visitado, bool &cicloEncontrado)
    {
        visitado[u] = true;

        for (int v : adj[u])
        {
            if (!visitado[v])
            {
                if (DFS(v, u, visitado, cicloEncontrado))
                {
                    adj[u].erase(v);
                    adj[v].erase(u);
                    mat[u][v] = 0;
                    mat[v][u] = 0;
                    cicloEncontrado = true;
                }
            }
            else if (v != pai && !cicloEncontrado)
            {
                cicloEncontrado = true;
            }
        }

        return cicloEncontrado;
    }

    void RemoveCiclos()
    {
        vector<bool> visitado(V + 1, false);
        bool cicloEncontrado = false;

        for (int i = 1; i <= V; i++)
        {
            if (!visitado[i])
            {
                if (DFS(i, i, visitado, cicloEncontrado))
                {
                    cicloEncontrado = true;
                }
            }
        }

        if (cicloEncontrado)
        {
            cout << "Ciclo(s) encontrado(s) e removido(s)!" << endl;
            ImprimeGrafo(*this);
        }
        else
        {
            cout << "Nenhum ciclo encontrado." << endl;
        }
    }
};

int main()
{
    Grafo g(5);
    g.AdicionarAresta(1, 2);
    g.AdicionarAresta(1, 3);
    g.AdicionarAresta(2, 3);
    g.AdicionarAresta(3, 4);
    g.AdicionarAresta(4, 5);
    g.AdicionarAresta(5, 3);

    Grafo::ImprimeGrafo(g);

    g.RemoveCiclos();

    Grafo::ImprimeGrafo(g);

    return 0;
}
