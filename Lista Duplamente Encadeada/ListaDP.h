#include "NodeDP.h"
template <typename T>
class ListaDP
{
private:
    NodeDP<T> *Head;
    NodeDP<T> *it;
    int N;

public:
    ListaDP()
    {
        Head = 0;
        N = 0;
    }
    ~ListaDP()
    {
        NodeDP<T> *P;
        while (N)
        {
            P = Head->next;
            NodeDP<T>::DesmontaNodeDP(Head);
            Head = P;
            N--;
        }
    }
    bool insert(T X)
    {
        NodeDP<T> *P = NodeDP<T>::MontaNodeDP(X);
        if (!P)
            return false;
        if (!Head)
        {
            Head = it = P->next = P->previous = P;
        }
        else
        {
            P->previous = Head->previous;
            P->next = Head;
            (Head->previous)->next = P;
            Head->previous = P;
            Head = P;
        }
        N++;
        return true;
    }
    int size()
    {
        return N;
    }
    T erase()
    {
        T R;
        NodeDP<T> *Aux;
        if (!Head)
            return R;
        Aux = it;
        if (it->next != it)
        {
            (it->next)->previous = it->previous;
            (it->previous)->next = it->next;
        }
        else
        {
            Head = 0;
        }
        if (Head == it)
        {
            Head = it = it->next;
        }
        else
        {
            it = it->next;
        }
        N--;
        R = NodeDP<T>::DesmontaNodeDP(Aux);
        return R;
    }
    NodeDP<T> *IT()
    {
        return it;
    }
    void IT_begin()
    {
        it = Head->next;
    }
    void ITMais()
    {
        it = it->next;
    }
    void ITMenos()
    {
        it = it->previous;
    }
};
