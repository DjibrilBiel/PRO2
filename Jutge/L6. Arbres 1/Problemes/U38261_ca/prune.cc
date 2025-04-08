#include "prune.hh"
using namespace std;
using namespace pro2;

pair<BinTree<int>, bool> prune_tree(BinTree<int> t, int x) {
    if (t.empty()) return make_pair(t, false);
    if (t.value() == x) return make_pair(BinTree<int>(), true);

    pair<BinTree<int>, bool> pruned_left = prune_tree(t.left(), x);
    pair<BinTree<int>, bool> pruned_right = prune_tree(t.right(), x);
    
    bool pruned = pruned_left.second or pruned_right.second;
    if (pruned) return make_pair(BinTree<int>(t.value(), pruned_left.first, pruned_right.first), true);
    return make_pair(t, false);
}