// Algoritmo para listar o grafo complementar G.

#include <iostream>
#include <list>
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
        // cria um grafo com vértices começando do inicio dado pelo usuário
        //  sendo inicio == 1
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

    static void ImprimeGrafoComplementar(Grafo g)
    {
        /* G' terá o mesmo conjunto de vértices que G.
         Em G',dois vértices serão adjacentes se não forem adjacentes em G.*/

        map<int, set<int>>::iterator it = g.adj.begin();
        map<int, set<int>> complentar;

        for (int i = 0; i < g.V; i++, it++)
        {
            for (int h = 0; h < g.V; h++)
            {
                if (g.mat[it->first][h] == 0 && h != it->first && h != 0) // podemos usar outra logica sem a matriz , mas é mais fácil
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

    Grafo ::ImprimeGrafoComplementar(grafo);

    return 0;
}
