#include "bintree.hh"
using namespace pro2;

struct Data {
    BinTree<int> R;
    int s;
};

Data sum_below_at_even_depth_funct(BinTree<int> t, int p) {
    if (t.empty()) return {t, 0};

    Data l = sum_below_at_even_depth_funct(t.left(), p + 1);
    Data r = sum_below_at_even_depth_funct(t.right(), p + 1);

    int s = l.s + r.s + t.value();
    if (p % 2 == 0) return {BinTree<int>(s, l.R, r.R), s};
    return {BinTree<int>(t.value(), l.R, r.R), s};
}

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
BinTree<int> sum_below_at_even_depth(BinTree<int> t) {
    return sum_below_at_even_depth_funct(t, 0).R;
}