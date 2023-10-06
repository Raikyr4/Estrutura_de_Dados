#include "Node.h"
template <typename T>

class Queue
{
private:
    Node<T> *Head; // ponteiro para Node<T> que ira apontar pra onde fica a cabeça/inicio da fila
    Node<T> *Tail; // ponteiro para node que ira apontar pra onde fica o final da fila/rabo
    int N;

public:
    Queue()
    {
        Head = Tail = nullptr;
        N = 0;
    }
    ~Queue()
    {
        Node<T> *P;
        while (Head)
        {
            Head = P->next;
            Node<T> ::DesmontaNode(P);
            P = Head;
        }
    }
    bool push(T X) // caso a fila n estiver vazia um elemento é add
    {
        Node<T> *P = Node<T> ::MontaNode(X);
        if (!P)
        {
            return false;
        }
        if (Head)
        {
            Tail->next = P;
        }
        else
        {
            Head = P;
        }
        Tail = P;
        Tail->next = 0;
        N++;
        return true;
    }
    T front()
    {
        T X;
        if (Head)
        {
            X = Head->D;
        }
        return X;
    }
    T pop()
    {
        T X;
        if (Head)
        {
            Node<T> *P = Head;
            Head = Head->next;
            X = Node<T>::DesmontaNode(P);
            if (!Head)
            {
                Tail = 0;
            }
            N--;
        }
        return X;
    }
    int size()
    {
        return N;
    }
    bool empty()
    {
        return !Head;
    }
};

