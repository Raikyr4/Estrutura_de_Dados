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
    // inicializa a minha tabela
    HashTable(int bsize)
    {
        tamanhoTabela = bsize;
        tabela = new list<Aluno>[tamanhoTabela];
    }

    ~HashTable() { delete[] tabela; }

    // calcula meu índice de hash
    int hashFunction(Aluno a)
    {
        return (a.getMatricula() % tamanhoTabela);
    }

    // recebe o Aluno e já coloca ele na tabela após ter chamado hashFunction
    void insertItem(Aluno a)
    {
        int index = hashFunction(a);
        tabela[index].push_back(a);
    }

    // busca e deleta o item da minha tabela
    void deleteItem(Aluno a)
    {
        int index = hashFunction(a);
        list<Aluno>::iterator i;
        for (i = tabela[index].begin(); i != tabela[index].end() && i->getMatricula() != a.getMatricula(); i++)
            ;

        if (i != tabela[index].end())
            tabela[index].erase(i);
    }

    // só imprime a tabela
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
    int n = 5;
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
    cout << "Apos deletar Jose:" << endl << endl;

    ht.deleteItem(aluno);

    ht.displayHashTable();

    return 0;
}