template <typename T>
// aki será criada um classe de Fila(FIFO)!!!!
//  SEM ALOCAÇÃO DINÂMICA , APENAS COM VETOR
class QueueVet
{
private:
    T *Vet;   // ponteiro do tipo de objeto que a pilha comportará
    int Head; // começo da fila onde sempre será retirado os elementos
    int Tail; // final da fila onde sera inserido os elementos
    int N;    // tamanho da fila

public:
    QueueVet(int n) // construtor que ir sertar um vetor de tamanho n para a fila
    {
        Vet = newT[n];
        Head = Tail = 0;
    }

    ~QueueVet() // destrutor que ira desalocar o vetor
    {
        delete[] Vet;
    }
    bool push(T X) // add um elemento na fila caso ela n estiver cheia
    {
        if ((Tail + 1) % N == Head)
            return false;
        Vet[Tail] = X;
        Tail = (Tail + 1) % N; // modo de avançar o tail e fazer com q ele, caso esteja no final dao vetor volte para o inicio fazendo com que a fila
        return true;
    }
    T front() // retorna o elemento da frente da fila caso ela estiver com algum elemento la dentro
    {
        return (Head == Tail) ? Vet[-1] : Vet[Head];
    }
    void pop() // remove um elemento da fila apenas avançando o Head e "esquecendo" do elemendo antigo naquela posição
    {
        if (Head != Tail)
        {
            Head = (Head + 1) % N;
        }
    }
    int size()
    {
        return (Tail - Head + N) % N;
    }
    bool empty()
    {
        return (Head == Tail);
    }
};
