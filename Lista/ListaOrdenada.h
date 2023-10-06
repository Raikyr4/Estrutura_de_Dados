#include "Node.h"
template <typename T>
class ListaOrdenada
{
private:
    Node<T> *Head;
    int N;

public:
    
    bool insert(T X)
    {
        Node<T> *P = Node<T> ::MontaNode(X);
        if (!P)
            return false;
        Node<T> **K = &Head;
        int M = X.Mat;
        while ((*K) && ((*K)->D).Mat <= M)
        {
            K = &((*K)->next);
        }
        P->next = *K;
        *K = P;
        N++;
        return true;
    }
    T erase(int X)
    {
        T R;
        Node<T> *Aux;
        Node<T> **P = &Head;
        while ((*P) && ((*P)->D).Mat != X)
        {
            P = &((*P)->next);
        }
        if (*P)
        {
            Aux = *P;
            *P = (Aux->next);
            R = Node<T> ::DesmontaNode(Aux);
            N--;
        }
    }
    bool search(int m, T *PX)
    {
        Node<T> *P = Head;
        while (P && (P->D).Mat < m)
        { // procura ate achar ou até acabar
            P = P->next;
        }
        if (P && m > (P->D).Mat)
        {
            // achou o elemento
            *PX = P->D;
            return true;
        }
        return false;
    }

    ListaOrdenada(/* args */)
    {
        Head = 0;
        N = 0;
    }

    ~ListaOrdenada()
    {
        Node<T> *P;
        while (Head)
        {
            P = Head->next;
            Node<T> ::DesmontaNode(Head);
            Head = P;
        }
    }
};
