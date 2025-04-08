#include "appendReverseOrder.hh"

void appendReverseOrder(list<int> &l) {
    int size = l.size();
    auto it = l.end();
    for (int i = 0; i < size; ++i) {
        --it;
        l.push_back(*it);
    }
}