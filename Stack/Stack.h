
#include "Node.h"
template <typename T>
/*aki será criado um classe Stack que usa alocamento dinâmico de memoria . A Pilha será composta por Nós !!!que possuem um elemento/trem/aluno  */
class Stack
{
private:
   Node <T> *top; // ponteiro para Node
    int N;     // tamanho da pilha

public:
    Stack()           // vai setar valores NULL paraNode <T> * top e N;
    {
    top = 0;
    N = 0;
}
    ~Stack()       // enquanto não estiver vazia ele irá desalocar os nodes criados
    {
       Node <T> *P;
        while (top)
        {
            P = top;
            top = top->next;
           Node <T> ::DesmontaNode(P);
        }
    } 
    bool push(T X) // add um elemento na pilha. Monta um Nó e passa os valores do parâmetro e o top pra dentro dele 
    {
       Node <T> *P =Node <T> ::MontaNode(X);
        if (!P)
            return false;
        P->next = top;
        top = P;
        N++;
        return true;
    }
    bool empty()
    {
        return !top;
    }
    T Top() // se a pilha não estiver vazia ele retorna o elemento do topo
    {
        T X;
        if (top)
            X = top->D;
        return X;
    }
    T pop() //se a pilha não estiver vazia a função guarda o top em um ponteiro de node  , aponta o top para o próximo e desaloca o o node do antigo top que será passado por ponteiro para o DesmontaNode 
    {
        T X;
        if (top)
        {
           Node <T> *P = top;
            top = top->next;
            X =Node <T> ::DesmontaNode(P);
            N--;
        }
        return X;
    }
    int size()
    {
        return N;
    }
};
