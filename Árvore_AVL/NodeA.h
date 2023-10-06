template <typename T >
class NodeT
{
public:
    T D;
    NodeT <T> *Left;
    NodeT <T> *Right;
    int fb;

public:
    static NodeT <T> *MontaNodeT(T Date)
    {
        NodeT <T>
            *P = new NodeT <T>;
        if (P)
        {
            P->D = Date;
            P->fb= 0;
            P->Left = 0;
            P->Right = 0;
        }
        return P;
    }
    static T DesmontaNodeT(NodeT <T> *P)
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
