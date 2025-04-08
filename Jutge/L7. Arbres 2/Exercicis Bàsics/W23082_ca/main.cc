#include <iostream>
using namespace std;

#include "tree-io.hh"
#include "tree.hh"
using namespace pro2;

/**
 * @brief Cerca un valor en un arbre.
 *
 * @param t Arbre.
 * @param x Valor a cercar.
 *
 * @returns Retorna `true` si `x` es troba en algun node de l'arbre `t`,
 *          `false` en cas contrari.
 */
bool tree_search(Tree<int> t, int x);


int main() {
    Tree<int> t;
    cin >> t;

    int x;
    while (cin >> x) {
        cout << x << ' ' << (tree_search(t, x) ? "true" : "false") << endl;
    }
}
