#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Aluno
{
public:
    Aluno() {}
    Aluno(long int m, string n) : matricula(m), nome(n) {}
    virtual ~Aluno() {}
    void setMatricula(long int m) { matricula = m; }
    void setNome(string n) { nome = n; }
    long int getMatricula() { return matricula; }
    string getNome() { return nome; }

private:
    long int matricula;
    string nome;
};

class HashTable
{
private:
    int tamanhoTabela;
    list<Aluno> *tabela;

public:
    HashTable(int bsize)
    {
        tamanhoTabela = bsize;
        tabela = new list<Aluno>[tamanhoTabela];
    }

    ~HashTable() { delete[] tabela; }

    int hashFunction1(Aluno a)
    {
        return (a.getMatricula() % tamanhoTabela);
    }

    int PrimoRelativo(int n)
    {
        // Lista de números primos de 0 a 100
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++)
        {
            if (n % primes[i] != 0)
            {
                return primes[i];
            }
        }

        // Se não encontrarmos um número primo que seja relativamente primo a n, retornamos 1
        return 1;
    }

    int hashFunction2(Aluno a)
    {
        int primoRelativo = PrimoRelativo(tamanhoTabela);
        return (primoRelativo - (a.getMatricula() % primoRelativo));
    }

    void insertItem(Aluno a)
    {
        int index = (hashFunction1(a) + hashFunction2(a)) % tamanhoTabela;
        tabela[index].push_back(a);
    }

    void deleteItem(Aluno a)
    {
        int index = (hashFunction1(a) + hashFunction2(a)) % tamanhoTabela;
        list<Aluno>::iterator i;
        for (i = tabela[index].begin(); i != tabela[index].end() && i->getMatricula() != a.getMatricula(); i++)
            ;

        if (i != tabela[index].end())
            tabela[index].erase(i);
    }

    void displayHashTable()
    {
        for (int i = 0; i < tamanhoTabela; i++)
        {
            cout << i;
            for (auto x : tabela[i])
                cout << " --> " << x.getNome();
            cout << endl;
        }
    }
};

int main()
{
    cout << endl
         << endl;

    vector<Aluno> dados;
    int n = 10;
    HashTable ht(n);
    for (int i = 0; i < n; i++)
    {
        Aluno user;
        string nome;
        long int mat;
        cout << "Digite o nome: " << i << ": ";
        cin >> nome;
        cout << "Digite a matricula: " << i << ": ";
        cin >> mat;
        user.setNome(nome);
        user.setMatricula(mat);
        dados.push_back(user);
    }

    for (int i = 0; i < n; i++)
        ht.insertItem(dados[i]);

    Aluno aluno(2014, "Jose");
    ht.insertItem(aluno);
    ht.displayHashTable();

    cout << endl
         << endl;
    cout << "Apos deletar Jose:" << endl
         << endl;

    ht.deleteItem(aluno);

    ht.displayHashTable();

    return 0;
}
