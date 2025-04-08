#include "bintree.hh"
using namespace pro2;

/**
 * @brief Calcula l'alçada d'un arbre binari
 * @param t Un arbre binari.
 * @returns L'alçada de l'arbre, segons la definició anterior.
 */
int height(BinTree<int> t) {
    if (t.empty()) return 0;

    int l = 1;
    int r = 1;
    l += height(t.left());
    r += height(t.right());

    if (l < r) return r;
    else return l;
}