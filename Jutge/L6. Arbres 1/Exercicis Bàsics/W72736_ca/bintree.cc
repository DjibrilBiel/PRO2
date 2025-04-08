#include "bintree.hh"
using namespace pro2;

/**
 * @brief Retorna l'arbre de sumes de `t`.
 *
 * L'arbre de sumes és un arbre binari amb la mateixa forma de `t` però a on cada valor conté la
 * suma dels valors del subarbre que penja de la mateixa posició a `t`.
 *
 * @param t L'arbre binari original.
 *
 * @returns L'arbre de sumes de `t`.
 */
BinTree<int> tree_of_sums(BinTree<int> t) {
    if (t.empty()) return BinTree<int>();
    
    BinTree<int> l, r;
    int ln = 0, rn = 0;

    if (not t.left().empty()) {
        l = tree_of_sums(t.left());
        ln = l.value();
    } 
    if (not t.right().empty()) {
        r = tree_of_sums(t.right());
        rn = r.value();
    }

    int n = t.value();
    n += ln + rn;
    
    BinTree<int> temp(n, l, r);
    return temp;
}