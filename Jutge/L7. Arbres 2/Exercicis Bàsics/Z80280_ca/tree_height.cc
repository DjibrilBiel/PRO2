#include "tree.hh"
using namespace pro2;
#include <vector>
using namespace std;

int tree_height(Tree<int> t) {
    if (t.empty()) return 0;

    int size = t.num_children();
    vector<int> height(size);
    int height_max = 0;

    for (int i = 0; i < size; ++i) {
        height[i] = tree_height(t.child(i));
        if (height_max < height[i]) height_max = height[i];
    }

    return height_max + 1;
}