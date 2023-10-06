#include <iostream>
template <typename T>
/* aki sera criada um classe que ira montar um "nó" que possui um trem/aluno e um ponteiro para outro "nó"
 o que permitirá com que a gente crie classes como fila e pilha("DE NÓS") com alocação dinâmica de memoria, em que tais estruturas nao possuirão posições contiguas como nas classes StackVet e QueueVet. As "posições" nessas classes a partir de agr serão acessadas através do endereço de memoria de um no que por sua vez guarda o endereço do próximo e assim por diante  */
class Node
{
public:
    T D;    // tipo de objeto que sera copiado para dentro do Nó
    Node<T> *next; // ponteiro que irá apontar para o Nó seguinte

public:
    static Node<T> *MontaNode(T Date) // método estático que nao roda em cima de um objeto da classe node , ele cria um ponteiro pra node que recebe um novo node que recebe um trem/aluno para dentro do seu D e o seu next aponta para null
    {
        Node<T> *P = new Node<T>;
        if (P)
        {
            P->D = Date;
            P->next =0;
        }
        return P;
    }
    static T DesmontaNode(Node<T> *P) // método estático que nao roda em cima de um objeto da classe node , ele salva o elemento do Nó que será excluído e logo após deleta o Nó que foi alocado e logo em seguida retorna o elemento salvo
    {
       T X;
        if (P)
        {
            X = P->D;
            delete P;
        }
        return X;
    }
};