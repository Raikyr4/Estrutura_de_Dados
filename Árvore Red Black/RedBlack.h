// escrever comentários sobre a teoria da RED Black pra cada função 

#include <iostream>
using namespace std;
enum Color
{
    RED,
    BLACK
};

class Node
{
public:
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;

    void leftRotate(Node *x);
    void rightRotate(Node *x);
    void insertFixup(Node *z);
    void deleteFixup(Node *x);
    Node *minimum(Node *x);
    Node *maximum(Node *x);
    void transplant(Node *u, Node *v);
    void destroyTree(Node *x);

public:
    RedBlackTree();
    ~RedBlackTree();

    Node *search(int data);
    void insert(int data);
    void remove(int data);
    void print(Node *node, int level = 0);
};

RedBlackTree::RedBlackTree() : root(nullptr) {}

RedBlackTree::~RedBlackTree()
{
    destroyTree(root);
}

void RedBlackTree::destroyTree(Node *x)
{
    if (x != nullptr)
    {
        destroyTree(x->left);
        destroyTree(x->right);
        delete x;
    }
}

Node *RedBlackTree::search(int data)
{
    Node *x = root;
    while (x != nullptr && data != x->data)
    {
        if (data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}

void RedBlackTree::leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nullptr)
    {
        root = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertFixup(Node *z)
{
    while (z->parent != nullptr && z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right;
            if (y != nullptr && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            Node *y = z->parent->parent->left;
            if (y != nullptr && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int data)
{
    Node *z = new Node(data);
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr)
    {
        y = x;
        if (z->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nullptr)
    {
        root = z;
    }
    else if (z->data < y->data)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    insertFixup(z);
}

void RedBlackTree::deleteFixup(Node *x)
{
    while (x != root && (x == nullptr || x->color == BLACK))
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK))
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right == nullptr || w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else
        {
            Node *w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK))
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left == nullptr || w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr)
        x->color = BLACK;
}

void RedBlackTree::remove(int data)
{
    Node *z = search(data);
    if (z == nullptr)
        return;

    Node *y = z;
    Node *x;
    Color y_original_color = y->color;

    if (z->left == nullptr)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nullptr)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z)
        {
            if (x != nullptr)
                x->parent = y;
        }
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right != nullptr)
                y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK)
    {
        deleteFixup(x);
    }

    delete z;
}

Node *RedBlackTree::minimum(Node *x)
{
    while (x->left != nullptr)
    {
        x = x->left;
    }
    return x;
}

Node *RedBlackTree::maximum(Node *x)
{
    while (x->right != nullptr)
    {
        x = x->right;
    }
    return x;
}

void RedBlackTree::transplant(Node *u, Node *v)
{
    if (u->parent == nullptr)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if (v != nullptr)
    {
        v->parent = u->parent;
    }
}

void RedBlackTree::print(Node *node, int level)
{
    if (node != nullptr)
    {
        print(node->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }
        cout << node->data;
        if (node->color == RED)
        {
            cout << " (Red)";
        }
        else
        {
            cout << " (Black)";
        }
        cout << endl;
        print(node->left, level + 1);
    }
}
