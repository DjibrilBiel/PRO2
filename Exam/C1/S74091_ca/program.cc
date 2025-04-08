#include "bintree.hh"
using namespace pro2;
#include <set>
using namespace std;

/**
 * @brief Retorna el conjunt dels valors dels nodes d'un arbre 
 *        binari que estan a la profunditat `depth`
 * 
 * @param  t      Arbre binari d'enters.
 * @param  depth  La profunditat dels nodes que es vol.
 *
 * @returns El conjunt de valors trobats a profunditat `depth`
 */
set<int> values_at_depth(BinTree<int> t, int depth) {
    if (t.empty()) return {};

    if (depth == 1) return {t.value()};

    set<int> left = values_at_depth(t.left(), depth - 1);
    set<int> right = values_at_depth(t.right(), depth - 1);

    for (auto it = left.begin(); it != left.end(); ++it) right.insert(*it);
    
    return right;
}