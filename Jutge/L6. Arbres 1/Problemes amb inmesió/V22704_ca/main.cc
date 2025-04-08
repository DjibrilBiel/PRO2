#include <iostream>
using namespace std;

#include "bintree-inline.hh"
#include "bintree-io.hh"
#include "bintree.hh"
#include "vector-io.hh"
using namespace pro2;

/**
 * @brief Retorna els valors dels nodes del camí més llarg de l'arbre binari `t`.
 *
 * Un camí va des de l'arrel de l'arbre fins a una full (un node sense fills).
 * Si hi ha més d'un camí màxim, cal retornar el que va per les branques de més
 * a l'esquerra possible.
 *
 * @param t L'arbre binari.
 *
 * @returns Els valors dels nodes del camí més llarg de `t`.
 */
vector<int> longest_leftmost_path(BinTree<int> t);

void main_inline() {
    string line;
    while (getline(cin, line)) {
        BinTree<int> t = bintree_inline_read<int>(line);
        print_vector(longest_leftmost_path(t));
    }
}

void main_visual() {
    BinTree<int> t;
    while (cin >> t) {
        print_vector(longest_leftmost_path(t));
    }
}

int main() {
    string format, line;
    getline(cin, format);  // determina el format dels arbres
    if (format == "inline") {
        main_inline();
    } else {
        main_visual();
    }
}
