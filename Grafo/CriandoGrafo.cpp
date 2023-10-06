#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    // grafo nao Direcionado , onde todo vertice que liga a outro o outro tbm vai pra ele
    //  X->Y
    //  Y->X

    map<int, set<int>> G;
    int origem, destino;

    cout << "Arcos do Garfo : " << endl;

    do
    {
        cout << "Add arco : " << endl;
        cout << "use -1 -1 para encerrar." << endl;
        cin >> origem >> destino;

        if (origem == -1)
            break;

        G[origem].insert(destino); // ver isso aki

    } while (1);

    cout << "Foram digitados : " << G.size() << " verticies"
         << "e " << endl;

    map<int, set<int>>::iterator it;

    for (it = G.begin(); it != G.end(); it++)
    {
        set<int>::iterator it2;
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            cout << it->first << " -> " << *it2 << endl;
        }
    }
}