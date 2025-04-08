#include <iostream>
using namespace std;

#include "tree-io.hh"
#include "tree.hh"
using namespace pro2;

/**
 * @brief Calcula l'alçada d'un arbre
 * @param t Un arbre.
 * @returns L'alçada de l'arbre, segons la definició anterior.
 */
int tree_height(Tree<int> t);

int main() {
    Tree<int> t;
    while (cin >> t) {
        cout << tree_height(t) << endl;
    }
}
