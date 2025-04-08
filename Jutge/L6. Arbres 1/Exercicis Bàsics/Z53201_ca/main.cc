#include <iostream>
using namespace std;

#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

/**
 * @brief Cerca un valor en un arbre binari.
 *
 * @param t Arbre binari.
 * @param x Valor a cercar.
 *
 * @returns Retorna `true` si `x` es troba en algun node de l'arbre `t`,
 *          `false` en cas contrari.
 */
bool cerca_valor(BinTree<int> t, int x);


int main() {
    BinTree<int> t;
    cin >> t;

    int x;
    while (cin >> x) {
        cout << x << ' ' << (cerca_valor(t, x) ? "true" : "false") << endl;
    }
}
