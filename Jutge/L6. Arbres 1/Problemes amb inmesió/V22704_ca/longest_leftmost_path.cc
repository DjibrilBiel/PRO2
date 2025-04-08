#include "bintree.hh"
using namespace pro2;
#include <vector>
using namespace std;

/**
 * @brief Retorna els valors del camí més llarg d'un arbre binari.
 *
 * Un camí va des de l'arrel de l'arbre fins a una fulla (un node sense fills).
 * Si hi ha més d'un camí màxim, cal retornar el que va per les branques de més
 * a l'esquerra possible.
 *
 * @param t L'arbre binari.
 * @returns Els valors dels nodes del camí més llarg de `t`.
 */
vector<int> longest_leftmost_path(BinTree<int> t) {
    if (t.empty()) return {};

    vector<int> l = longest_leftmost_path(t.left());
    vector<int> r = longest_leftmost_path(t.right());

    if (l.size() >= r.size()){
        l.insert(l.begin(), t.value());
        return l;
    } 
    r.insert(r.begin(), t.value());
    return r;
}