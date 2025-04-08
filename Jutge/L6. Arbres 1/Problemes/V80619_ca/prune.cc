#include "prune.hh"
using namespace std;
using namespace pro2;

pair<BinTree<int>,bool> prune_tree(BinTree<int> t, int x) {
    if (t.empty()) return make_pair(BinTree<int>(), false);
    if (t.value() == x) return make_pair(BinTree<int>(), true);

    pair<BinTree<int>, bool> l(prune_tree(t.left(), x));
    pair<BinTree<int>, bool> r(prune_tree(t.right(), x));
    
    BinTree<int> tmp(t.value(), l.first, r.first);

    return make_pair(tmp, l.second or r.second);
}