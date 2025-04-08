#include <iostream>
using namespace std;

#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

/**
 * @brief Suma els valors d'un arbre binari.
 * 
 * Si un node de l'arbre és buit, el seu valor és 0. 
 *
 * @param t Arbre binari.
 *
 * @returns La suma dels valors dels nodes de l'arbre `t`.
 */
int suma_valors(BinTree<int> t);

int main() {
    BinTree<int> t;
    while (cin >> t) {
        cout << suma_valors(t) << endl;
    }
}
