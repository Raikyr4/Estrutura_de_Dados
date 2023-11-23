#include <vector>
#include <iostream>
using namespace std;

int Hash(int key, int tableSize)
{
    return key % tableSize;
}

int main()
{
    int tableSize = 10; // vai influenciar no cálculo do Hash

    vector<int> tabelaHash(tableSize, -1);

    // Chaves para inserir na tabelaHash
    vector<int> keys = {50, 700, 76, 85, 92, 73, 101};

    // Inserir as chaves na tabelaHash
    for (int key : keys)
    {
        int i = Hash(key, tableSize);
        tabelaHash[i] = key;
    }

    for (int i = 0; i < tableSize; i++)
    {
        cout << "Indice: " << i << ", Chave: " << tabelaHash[i] << endl;
    }

    return 0;
}
