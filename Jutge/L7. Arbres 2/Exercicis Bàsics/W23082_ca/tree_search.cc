#include "tree.hh"
using namespace pro2;

bool tree_search(Tree<int> t, int x) {
    if (t.empty()) return false;
    if (t.value() == x) return true;

    bool found = false;
    int i = 0;
    while (i < t.num_children() and not found) {
        found = tree_search(t.child(i), x);
        ++i;
    }

    return found;
}