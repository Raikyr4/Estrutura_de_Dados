#include <iostream>
#include <set>
#include <map>
using namespace std;

class Grafo
{
public:
    int V;
    map<int, set<int>> adj; // como se fosse a matriz de adjacência

public:
    Grafo(int V)
    {
        // cria um grafo com vértices começando do 0
        for (int i = 0; i < V; i++)
        {
            set<int> x;
            adj.insert({i, x});
        }
    }

    Grafo(int V, int incio)
    {
        // cria um grafo com vértices começando do inicio dado pelo usuário
        //  sendo inicio > 0
        if (incio == 1)
        {
            for (int i = incio; i <= V; i++)
            {
                set<int> x;
                adj.insert({i, x});
            }
        }
        else
        {
            cout << "Esse Construtor so aceita incicar o Grafo a partir do vertice = 1" << endl;
        }
    }

    void AdicionarAresta(int n, int m)
    {
        // assim o grafo fica direcionado :  X -> Y
        adj[n].insert(m);

        // se for pra ser bidirecional ou seja nao direcionado  : X <-> Y ou  X - Y
        // adj[m].insert(n);
    }

    static void ImprimeGrafo(map<int, set<int>> g)
    {
        cout << endl
             << "Grafo : " << endl;
        for (auto it : g)
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

    void Ordena()
    {
        map<int, set<int>>::iterator it;
        it = adj.begin();

        while (!adj.empty())
        {
            if (it->second.size() == 0)
            {
                cout << it->first << ' ';
                map<int, set<int>>::iterator it2;

                for (it2 = adj.begin(); it2 != adj.end(); it2++)
                {
                    if (it2->second.find(it->first) != it2->second.end())
                    {
                        it2->second.erase(*(it2->second.find(it->first)));
                    }
                }
                map<int, set<int>>::iterator auxIt;
                auxIt = it;
                it++;
                adj.erase(auxIt->first);
            }
            else
            {
                it++;
            }
            if (it == adj.end())
                it = adj.begin();
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
    Grafo ::ImprimeGrafo(grafo.adj);
    grafo.Ordena();
    /*
     
    cout << endl;
    cout << endl
         << "Informe o a quantidade de Verticies do Grafo: ";
    cin >> v;
    Grafo grafo2(v,1);

    cout << endl
         << "Informe o numero de pacotes e as dependencias (no formato 'x y', -1 -1 para encerrar):" << endl;
    cin >> n >> m;

    while (m != -1 && n != -1)
    {
        grafo2.AdicionarAresta(n, m);
        cin >> n >> m;
    }
    Grafo ::ImprimeGrafo(grafo2.adj);
    grafo2.Ordena();
     

     */

    return 0;
}

// Lembre - se que o grafo tem que ser acíclico
/*
    Use essa Entrada :
         6
        0 3
        1 3
        1 2
        2 4
        2 3
        4 0
        5 0
        -1 -1
 */