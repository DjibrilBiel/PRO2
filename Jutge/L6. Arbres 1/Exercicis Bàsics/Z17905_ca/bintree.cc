#include "bintree.hh"
using namespace pro2;

/**
 * @brief Retorna l'arbre de mides de `t`.
 *
 * L'arbre de mides és un arbre binari amb la mateixa forma que `t` però a on cada valor conté la
 * quantitat total de nodes del subarbre que penja de la mateixa posició a `t`.
 *
 * @param t L'arbre binari original.
 *
 * @returns L'arbre de mides de `t`.
 */
BinTree<int> tree_of_sizes(BinTree<int> t) {
    if (t.empty()) return BinTree<int> ();

    BinTree<int> l, r;
    int ls = 0, rs = 0;

    if (not t.left().empty()) {
        l = tree_of_sizes(t.left());
        ls = l.value();
    } 
    if (not t.right().empty()) {
        r = tree_of_sizes(t.right());
        rs = r.value();
    }

    int n;
    n = ls + rs + 1;

    BinTree<int> temp(n, l, r);
    return temp;
}