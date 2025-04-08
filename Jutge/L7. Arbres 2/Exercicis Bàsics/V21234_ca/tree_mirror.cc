#include "tree.hh"
using namespace pro2;
#include <vector>
using namespace std;

Tree<int> tree_mirror(Tree<int> t) {
    if (t.empty()) return t;

    int size = t.num_children();
    vector<Tree<int>> tree(size);
    for (int i = 0; i < size; ++i) tree[size - i - 1] = tree_mirror(t.child(i));

    return Tree<int>(t.value(), tree);
}