#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

#include <iostream>
using namespace std;

/**
 * @brief Retorna un arbre binari que és el mirall de l'arbre `t`.
 * 
 * Un arbre binari és el mirall d'un altre si les seves branques esquerra i dreta
 * estan intercanviades recursivament en tots els nodes.
 * 
 * @param t L'arbre binari original.
 * 
 * @returns Un arbre binari que és el mirall de l'arbre `t`.
 */
BinTree<int> reverse_tree(BinTree<int> t);

int main() {
    BinTree<int> t;
    while (cin >> t) {
        cout << reverse_tree(t);
    }
}
