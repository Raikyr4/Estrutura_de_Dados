#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Grafo
{
public:
    int V;                     // quantidade de vertices do grafo
    map<int, set<int>> adj;    // grafo organizado a partir de map e set
    int mat[100][100] = {{0}}; // matriz de adjacência do grafo
    vector<int> visited;      // vetor de visitados, usado para verificar se um vértice foi visitado ou não

public:
    // cria um grafo com vértices começando do início , sendo o início == 1 sempre
    Grafo(int V)
    {
       this->V = V;
        visited.push_back(-1);
        for (int i = 1; i <= V; i++)
        {
            set<int> x;
            adj.insert({i, x});
            visited.push_back(0);
        }
    }

    // adiciona arestas de forma que o Grafo seja não direcionado ou bidirecional
    void AdicionarAresta(int n, int m)
    {
        // assim o grafo fica não direcionado :  X <-> Y
        adj[n].insert(m);
        adj[m].insert(n);

        mat[n][m] = 1;
        mat[m][n] = 1;

        // assim o grafo fica direcionado  : X -> Y
        /*
            adj[n].insert(m);

            mat[n][m] = 1;
        */
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

    // descobre o grafo complementar de um grafo G e imprime ele na tela
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
                if (g.mat[it->first][h] == 0 && h != it->first && h != 0) // podemos usar outra logica sem a ma
                {
                    complentar[it->first].insert(h);
                    complentar[h].insert(it->first);
                }
            }
        }

        cout << endl
             << "Grafo Complementar : " << endl;
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

    /* realiza uma ordenação topológica, imprimindo na tela
       adotando que o grafo seja direcionado
       para mudar isso , basta alterar a função AdicionarAresta*/
    void OrdenacaoTopologica()
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

    /* verifica se tem Vertices desconexos no grafo e os imprime na tela,
       adotando que o grafo seja não direcionado
       para isso , basta alterar a função AdicionarAresta*/
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
