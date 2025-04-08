#include "bintree.hh"
using namespace pro2;

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
BinTree<int> reverse_tree(BinTree<int> t) {
    if (t.empty()) return BinTree<int>();
    
    BinTree<int> l, r;
    if (not t.left().empty()) l = reverse_tree(t.left());
    if (not t.right().empty()) r = reverse_tree(t.right());

    return BinTree<int>(t.value(), r, l);
}