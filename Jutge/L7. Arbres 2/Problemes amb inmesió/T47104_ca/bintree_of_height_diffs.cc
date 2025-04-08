#include "bintree.hh"
using namespace pro2;

struct HeightTree {
    BinTree<int> D;
    int height;
};

HeightTree bintree_of_height_diffs_funct(BinTree<int> s) {
    if (s.empty()) return {s, 0};

    HeightTree l = bintree_of_height_diffs_funct(s.left());
    HeightTree r = bintree_of_height_diffs_funct(s.right());

    int h;
    if (l.height >= r.height) h = l.height;
    else h = r.height;

    return {BinTree<int>(l.height - r.height, l.D, r.D), h + 1};
}

BinTree<int> bintree_of_height_diffs(BinTree<int> t) {
    return bintree_of_height_diffs_funct(t).D;
}