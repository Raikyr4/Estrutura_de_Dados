template <typename T>
class NodeDP
{
public:
    T D;
   NodeDP <T> *next;
   NodeDP <T> *previous;

public:
    static NodeDP <T> *MontaNodeDP(T Date)
    {
       NodeDP <T> *P = new NodeDP;
        if (P)
        {
            P->D = Date;
            P->next = 0;
            P->previous = 0;
        }
        return P;
    }
    static T DesmontaNodeDP(NodeDP<T> *P) 
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

