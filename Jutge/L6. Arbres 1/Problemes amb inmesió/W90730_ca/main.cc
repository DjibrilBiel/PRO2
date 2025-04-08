#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

#include "bintree-inline.hh"
#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

/**
 * @brief Retorna l'arbre de sumes de `t`.
 *
 * L'arbre de sumes és un arbre binari amb la mateixa forma de `t` però a on cada valor conté la
 * suma dels valors del subarbre que penja de la mateixa posició a `t`.
 *
 * @param t L'arbre binari original.
 *
 * @returns L'arbre de sumes de `t`.
 */
BinTree<int> sort_tree(BinTree<int> t);

void main_visual() {
    BinTree<int> t;
    while (cin >> t) {
        cout << sort_tree(t);
    }
}

void main_inline() {
    string line;
    while (getline(cin, line)) {
        BinTree<int> t = bintree_inline_read<int>(line);
        BinTree<int> D = sort_tree(t);
        bintree_inline_write(D);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    string format, line;
    getline(cin, format);  // determina el format dels arbres
    if (format == "inline") {
        main_inline();
    } else {
        main_visual();
    }
}
