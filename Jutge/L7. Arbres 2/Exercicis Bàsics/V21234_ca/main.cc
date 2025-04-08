#include "tree-io.hh"
#include "tree.hh"
using namespace pro2;

#include <iostream>
using namespace std;

/**
 * @brief Retorna un arbre que és el mirall de l'arbre `t`.
 * 
 * Un arbre és el mirall d'un altre si les seves branques esquerra i dreta
 * estan intercanviades recursivament en tots els nodes.
 * 
 * @param t L'arbre original.
 * 
 * @returns Un arbre que és el mirall de l'arbre `t`.
 */
Tree<int> tree_mirror(Tree<int> t);

int main() {
    Tree<int> t;
    while (cin >> t) {
        cout << tree_mirror(t);
    }
}
