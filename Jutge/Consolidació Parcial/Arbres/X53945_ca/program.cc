#include "treeOfSumsOfAncestors.hh"

BinTree<int> i_treeOfSumsOfAncestors(const BinTree<int> t, int n) {
    if (t.empty()) return t;

    n += t.value();

    BinTree<int> l = i_treeOfSumsOfAncestors(t.left(), n);
    BinTree<int> r = i_treeOfSumsOfAncestors(t.right(), n);

    return BinTree<int>(n, l, r);
}

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
    return i_treeOfSumsOfAncestors(t, 0);
}