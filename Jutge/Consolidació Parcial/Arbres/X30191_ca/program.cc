#include "numNegative.hh"
#include "utils.hh"

pair<int, int> i_numNegative(BinTree<string> t) {
    string val = t.value();

    if (isNumber(val)) return {mystoi(val), 0};

    auto l = i_numNegative(t.left());
    auto r = i_numNegative(t.right());
    int n = l.second + r.second;

    int result;
    if (val == "+") result = l.first + r.first;
    else if (val == "-") result = l.first - r.first;
    else result = l.first * r.first;

    if (result < 0) ++n;
    return {result, n};
}

int numNegative(BinTree<string> t) {
    return i_numNegative(t).second;
}