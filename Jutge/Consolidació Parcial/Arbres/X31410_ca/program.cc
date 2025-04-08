#include "numIncreasing.hh"

int i_numIncreasing(BinTree<int> t, int n) {
    if (t.empty()) return 0;

    return (n < t.value()) + i_numIncreasing(t.left(), t.value()) + i_numIncreasing(t.right(), t.value());
}

int numIncreasing(BinTree<int> t) {
    return i_numIncreasing(t, t.value());
}