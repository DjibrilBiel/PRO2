#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    string val = t.value();

    if (val == "true") return BinTree<bool>(true);
    if (val == "false") return BinTree<bool>(false);

    BinTree<bool> l = treeOfEvaluations(t.left());

    if (val == "not") return BinTree<bool>(not l.value(), l, BinTree<bool>());

    BinTree<bool> r = treeOfEvaluations(t.right());

    if (val == "and") return BinTree<bool>(l.value() and r.value(), l, r);
    return BinTree<bool>(l.value() or r.value(), l, r);
}