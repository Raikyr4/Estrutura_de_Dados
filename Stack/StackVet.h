template <typename T>
// aki criaremos uma classe de Pilha (LIFO)!!!!
//  SEM ALOCAÇÃO DINÂMICA , APENAS COM VETOR
class StackVet
{
private:
    T *V;    // ponteiro do tipo de objeto que a pilha comportará
    int Top; // topo da pilha
    int N;   // quantidade de elementos dentro da pilha

public:
    StackVet(int n) // construtor atribui/"seta"/aloca valores iniciais na pilha quando o objeto é instanciado
    {
        V = new T[n]; //  modo de alocar um vetor de forma dinâmica
        N = n;
        Top = -1;
    }           
    ~StackVet()// desaloca o espaço de memoria usado no main ao instanciar o objeto da classe satckvet
    {
        delete[] V; // modo de desalocar um vetor de forma dinâmica
    }
    T top()      // retorna o elemento do topo
    {
        return V[Top];
    }
    bool push(T X) // adiciona um elemento no topo da pilha se ela n estiver cheia
    {
        if (Top < N - 1)
        {
            V[++Top] = X;
            return true;
        }
        return false;
    }
    void pop() // remove um elemento do topo da pilha caso a pilha n estiver vazia
    {
        if (Top >= 0)
        {
            Top--;
        }
    }
    bool empty() // retorna se a pilha esta vazia ou nao
    {
        return (Top == -1);
    }
    int size()
    {
        return Top + 1;
    }
    bool full()
    {

        return !(Top + 1 - N);
    }
};

