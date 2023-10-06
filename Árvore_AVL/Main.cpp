#include "ABBAVL.h"
#include <iostream>
using namespace std;
int main()
{
   ABBAVL<int> B;
   //Inserção de elementos na árvore 
   cout<<"comecando o insert"<<endl;
   B.insert(23);  
   B.insert(18);
   B.insert(30);
   B.insert(6);
   B.insert(1);
   B.insert(7);
   B.insert(60);
   B.insert(5);
   cout<<"Percorrendo em ordem : "<<endl;
   B.PERCORRER_INORDER(B.getRoot()); // mostra todos os elementos da arvore 
   cout<<endl<<endl;

   cout<<"Altura Da Arvore : "<<ABBAVL<int> :: Heigh(B.getRoot())<<endl;

   cout<<"O menor elemento da arvore eh "<<ABBAVL<int>:: RMin(B.getRoot())->D<<endl;

   cout<<"O maior elemento dessa arvore eh "<<ABBAVL <int> :: RMax(B.getRoot())->D<<endl;

   B.erase(6);// apagando um elemento da arvore

   cout<<"O Elemento buscado foi o "<<ABBAVL<int> :: SEARCH(B.getRoot(),30)->D<<endl;

    cout<<endl<<"Percorrendo em ordem apos delete : "<<endl;
   B.PERCORRER_INORDER(B.getRoot()); // mostra todos os elementos da arvore 
   cout<<endl;
}