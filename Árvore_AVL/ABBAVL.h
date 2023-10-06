#include "NodeA.h"
#include <iostream>
using namespace std;

template <class T>
/*
The tree created here is an ABBAVL - AVL balanced tree from SEARCH!
    => AVL Balancing consists of keeping the BALANCE FACTOR within the values ​​{+1, 0 ,-1} , through ROTATION techniques (double or single)

   => To perform the rotations, the balance factor (Fb) of each node must be verified during insertion and deletion. whether Single Rotation Right or Left .To use Double Rotation is the opposite.
 */
class ABBAVL
{
private:
    NodeT<T> *Root;
    int N;

public:
    ABBAVL(/* args */)
    {
        Root = 0;
        N = 0;
    }
    int size()
    {
        return N;
    }
    NodeT<T> * getRoot()
    {
        return Root;
    }
    static NodeT<T> *RMin(NodeT<T> *Rot)
    {
        NodeT<T> *R = Rot;
        while (R->Left!=0)
        {
            R = R->Left;
        }
        return R;
    }
    static NodeT<T> *RMax(NodeT<T> *Rot)
    {
        NodeT<T> *R = Rot;
        while (R->Right!=0)
        {
            R = R->Right;
        }
        return R;
    }
    static int Heigh(NodeT<T> *R)
    {
        if (R == 0)
            return 0;
        else
        {
            int he = Heigh(R->Left);
            int hd = Heigh(R->Right);
            if (he < hd)
                return hd + 1;
            else
              return  he + 1;
        }
    }
    static void RSD(NodeT<T> **R)
    {
        NodeT<T> *a = *R;
        NodeT<T> *b = a->Left;
        a->Left = b->Right;
        b->Right = a;
        *R = b;
        if (b->fb == -1)
        {
            a->fb = b->fb == 0;
        }
        else
        {
            a->fb = -1;
            b->fb = 1;
        }
    }
    static void RSE(NodeT<T> **R)
    {
        NodeT<T> *a = *R;
        NodeT<T> *b = a->Right;
        a->Right = b->Left;
        b->Left = a;
        *R = b;
        if (b->fb == 1)
        {
            a->fb = b->fb == 0;
        }
        else
        {
            a->fb = 1;
            b->fb = -1;
        }
    }
    static void RDD(NodeT<T> **R)
    {
        NodeT<T> *a = *R;
        NodeT<T> *b = a->Left;
        NodeT<T> *c = b->Right;
        b->Right = c->Left;
        a->Left = c->Right;
        c->Right = a;
        c->Left = b;
        *R = c;
        if (c->fb == 0)
        {
            a->fb = b->fb = 0;
        }
        else
        {
            if (c->fb == -1)
            {
                b->fb = c->fb = 0;
                a->fb = 1;
            }
            else
            {
                c->fb = a->fb = 0;
                b->fb = -1;
            }
        }
    }
    static void RDE(NodeT<T> **R)
    {
        NodeT<T> *a = *R;
        NodeT<T> *b = a->Right;
        NodeT<T> *c = b->Left;
        b->Left = c->Right;
        a->Right = c->Left;
        c->Left = a;
        c->Right = b;
        *R = c;
        if (c->fb == 0)
        {
            a->fb = b->fb = 0;
        }
        else
        {
            if (c->fb == 1)
            {
                b->fb = c->fb = 0;
                a->fb = -1;
            }
            else
            {
                c->fb = a->fb = 0;
                b->fb = 1;
            }
        }
    }
    static bool INSERT(NodeT<T> **R, NodeT<T> *aux)
    {
        if (!(*R))
        {
            *R = aux;
            aux->fb = 0;
            return true;
        }
        if (((*R)->D) == (aux->D))
        {
            NodeT<T>::DesmontaNodeT(aux);
            return false;
        }
        if ((aux->D) < (*R)->D)
        { // insere para esquerda
            if (ABBAVL ::INSERT((&(*R)->Left), aux))
            { // aumentou esquerda
                if ((*R)->fb == 0)
                {
                    (*R)->fb = -1;
                    return true;
                }
                if ((*R)->fb == 1)
                {
                    (*R)->fb = 0;
                    return false;
                }
                if (((*R)->Left)->fb == -1)
                {
                    ABBAVL ::RSD(R);
                    return false;
                }
                ABBAVL ::RDD(R);
                return false;
            }
            return false;
        }
        if ((aux->D) > (*R)->D)
        {
            if (ABBAVL ::INSERT((&(*R)->Right), aux))
            {
                if ((*R)->fb == 0)
                {
                    (*R)->fb = 1;
                    return true;
                }
                if ((*R)->fb == -1)
                {
                    (*R)->fb = 0;
                    return false;
                }
                if (((*R)->Right)->fb == 1) 
                {
                    ABBAVL ::RSE(R);
                    return false;
                }
                ABBAVL ::RDE(R);
                return false;
            }
            return false;
        }
    }
    static bool ERASE(NodeT<T> **R, T X, NodeT<T> *A)
    {
        if (!(*R))
            return false;
        if (X < ((*R)->D))
        {
            if (ABBAVL ::ERASE((&((*R)->Left)), X, A))
            { // excluiu e reduziu para esquerda
                if ((*R)->fb == -1)
                {
                    (*R)->fb = 0;
                    return true;
                }
                if ((*R)->fb == 0)
                {
                    (*R)->fb = 1;
                    return false;
                }
                // Rotacionar agora !
                if ((*R)->fb >= 0)
                {
                    ABBAVL ::RSD(R);
                    return true;
                }
                ABBAVL ::RDD(R);
                return true;
            }
            return false;
        }
        if (X > ((*R)->D))
        {
            if (ABBAVL ::ERASE((&((*R)->Right)),X, A))
            { // excluiu e reduziu para esquerda
                if ((*R)->fb == 1)
                {
                    (*R)->fb = 0;
                    return true;
                }
                if ((*R)->fb == 0)
                {
                    (*R)->fb = -1;
                    return false;
                }
                // Rotacionar agora !
                if ((*R)->fb <= 0)
                {
                    ABBAVL ::RSE(R);
                    return true;
                }
                ABBAVL ::RDE(R);
                return true;
            }
            return false;
        }
        if (!(*R)->Left)
        {
            A = *R;
            *R = (*R)->Right;
            return true;
        }
        if (!(*R)->Right)
        {
            A = *R;
            *R = (*R)->Left;
            return true;
        }
        NodeT<T> *M = ABBAVL ::RMin((*R)->Right);
        swap(M->D, (*R)->D);

        if (ABBAVL ::ERASE((&((*R)->Right)),X, A))
        { // excluiu e reduziu para esquerda
            if ((*R)->fb == 1)
            {
                (*R)->fb = 0;
                return true;
            }
            if ((*R)->fb == 0)
            {
                (*R)->fb = -1;
                return false;
            }
            // Rotacionar agora !
            if ((*R)->fb <= 0)
            {
                ABBAVL ::RSE(R);
                return true;
            }
            ABBAVL ::RDE(R);
            return true;
        }
        return false;
    }
    void PERCORRER_INORDER(NodeT<T> *R)
    {
        if (!R) return ;
        PERCORRER_INORDER(R->Left);
        cout << R->D << " ";
        PERCORRER_INORDER(R->Right);
    }
    static NodeT<T> *SEARCH(NodeT<T> *R, int x)
    {
        if (!R || (R->D)== x)
        {
            return R;
        }
        if (x < (R->D))
        {
            return ABBAVL <T> :: SEARCH(R->Left, x);
        }
        return ABBAVL <T> :: SEARCH(R->Right, x);
    }
    bool insert(T Data)
    {
        NodeT<T> *P = NodeT<T>::MontaNodeT(Data);
        if (!P)
            return false;

        ABBAVL :: INSERT(&Root,P);
        N++;
        return true;
    }
    T erase(int M)
    {
       NodeT <T> *Aux;
       ABBAVL<T> :: ERASE(&Root,M,Aux);
       N--;
       return Aux->D;
    }

};
