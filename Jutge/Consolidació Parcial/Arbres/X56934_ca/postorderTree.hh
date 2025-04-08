#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en postordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> postorderTree(BinTree<int> t);
