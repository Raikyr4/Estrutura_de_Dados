#include "Node.h"
template <typename T>
class List
{
private:
  Node<T> *Head;
  int N;

public:
  List()
  {
    N = 0;
    Head = 0;
  }
  ~List()
  {
    Node<T> *P;
    while (Head)
    {
      P = Head->next;
      Node<T>::DesmontaNode(Head);
      Head = P;
    }
  }
  bool insert(T X)
  {
    Node<T> *P = Node<T>::MontaNode(X);
    if (!P)
    {
      return false;
    }
    P->next = Head;
    Head = P;
    N++;
    return true;
  }
  bool search(int m, T *PX)
  {
    Node<T> *P = Head;
    while (P && (P->D).Mat != m)
    { // procura ate achar ou até acabar
      P = P->next;
    }
    if (P)
    {
      // achou o elemento
      *PX = P->D;
      return true;
    }
    return false;
  }
  T erase(int X) // apaga o elemento passado por parametro dentro da lista
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
      R = Node<T>::DesmontaNode(Aux);
      N--;
    }
    return R;
  }
};
