#include "postorderTree.hh"

pair<BinTree<int>, int> postorderTree_f(BinTree<int> t, int n) {
    if (t.empty()) return {t, n};

    auto left = postorderTree_f(t.left(), n);
    auto right = postorderTree_f(t.right(), left.second);

    return {BinTree<int>(right.second, left.first, right.first), right.second+1};
}

BinTree<int> postorderTree(BinTree<int> t) {
    return postorderTree_f(t, 1).first;
}