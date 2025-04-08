#include "bintree.hh"
using namespace pro2;

struct TreeAndSum {
    BinTree<int> tree;
    int sum;
};

TreeAndSum sort_tree_with_sum(BinTree<int> t) {
    if (t.empty()) return {t, 0};

    TreeAndSum l = sort_tree_with_sum(t.left());
    TreeAndSum r = sort_tree_with_sum(t.right());

    int total = t.value() + l.sum + r.sum;
    if (l.sum <= r.sum) return {BinTree<int>(t.value(), l.tree, r.tree), total};
    return {BinTree<int>(t.value(), r.tree, l.tree), total};
}

BinTree<int> sort_tree(BinTree<int> t) {
    return sort_tree_with_sum(t).tree;
}