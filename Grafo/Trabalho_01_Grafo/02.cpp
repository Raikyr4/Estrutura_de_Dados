// Algoritimo que Verifica se no grafo há algum componente desconexo

#include <iostream>
#include <set>
#include <map>
using namespace std;

class Grafo
{
public:
    int V;
    map<int, set<int>> adj; // como se fosse a matriz de adjacência
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
        // assim o grafo fica nao direcionado :  X <-> Y
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

    void VerticiesDesconexos()
    {
        map<int, set<int>>::iterator it, it2;
        it = adj.begin();
        while (it != adj.end())
        {
            if (it->second.size() == 0)
            {
                cout << it->first << " ";
                map<int, set<int>>::iterator auxIt;
                auxIt = it;
                it++;
                adj.erase(auxIt->first);
            }
            else
            {
                it++;
            }
        }
        cout << endl;
    }
};

int main()
{
    int n, m, v;

    cout << endl
         << "Informe o a quantidade de Verticies do Grafo: ";
    cin >> v;
    Grafo grafo(v);

    cout << endl
         << "Informe o numero de pacotes e as dependencias (no formato 'x y', -1 -1 para encerrar):" << endl;
    cin >> n >> m;

    while (m != -1 && n != -1)
    {
        grafo.AdicionarAresta(n, m);
        cin >> n >> m;
    }
    Grafo ::ImprimeGrafo(grafo);
    grafo.VerticiesDesconexos();
    return 0;
}
