#include "RedBlack.h"

using namespace std;

int main()
{
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(2);
    tree.insert(7);
    tree.insert(17);

    tree.print(tree.search(10)); // Output: 10 (Black)
    tree.print(tree.search(15)); // Output: 15 (Red)
    tree.print(tree.search(25)); // Output: 25 (Black)

    tree.remove(15);

    tree.print(tree.search(15)); // Output: nullptr

    return 0;
}