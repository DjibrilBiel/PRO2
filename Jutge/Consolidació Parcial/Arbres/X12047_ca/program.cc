#include "numberOfLeaves.hh"

int numberOfLeaves(BinTree<int> t) {
    if (t.empty()) return 0;

    int left = numberOfLeaves(t.left());
    int right = numberOfLeaves(t.right());

    int sum = left + right;

    if (sum == 0) return 1;
    return sum;
}