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
bool cerca_valor(BinTree<int> t, int x) {
    if (t.empty()) return false;

    bool found = t.value() == x;
    if (found) return true;

    found = cerca_valor(t.left(), x);
    if (found) return true;

    found = cerca_valor(t.right(), x);
    return found;
}