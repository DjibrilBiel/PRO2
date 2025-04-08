#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

#include "bintree-inline.hh"
#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

/**
 * @brief Retorna l'arbre `t` reemplaçant els valors dels nodes a profunditat parell per la suma per sota
 *
 * @param t L'arbre binari original.
 *
 * @returns Un arbre binari R amb la mateixa estructura que t.
 * Per a cada posició p de t i R, si p és a profunditat senar,
 * llavors t i R tenen el mateix valor a posició p.
 * En canvi, si p es a profunditat parell, llavors el valor de R a posició
 * p és la suma de tots els valors que es troben a t a posició p i per sota.
 */
BinTree<int> sum_below_at_even_depth(BinTree<int> t);

void main_visual() {
    BinTree<int> t;
    while (cin >> t) {
        cout << sum_below_at_even_depth(t);
    }
}

void main_inline() {
    string line;
    while (getline(cin, line)) {
        BinTree<int> t = bintree_inline_read<int>(line);
        BinTree<int> D = sum_below_at_even_depth(t);
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
