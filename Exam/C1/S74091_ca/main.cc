#include "bintree-inline.hh"
#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

#include <set>
#include <iostream>
using namespace std;

/**
 * @brief Retorna el conjunt dels valors dels nodes d'un arbre 
 *        binari que estan a certa profunditat
 * 
 * La profunditat d'un node és:
 * a) 1       si és l'arrel (no té pare).
 * b) p + 1   si el pare del node té profunditat `p`.
 * 
 * @param t     Arbre binari d'enters.
 * @param depth La profunditat dels nodes que es vol.
 *
 * @returns El conjunt de valors trobats a profunditat `depth`
 */
set<int> values_at_depth(BinTree<int> t, int depth);

int read_int(string line) {
    istringstream iss(line);
    int x;
    iss >> x;
    return x; 
}

ostream& operator<<(ostream& o, const set<int>& S) {
    o << "{";
    for (int x : S) {
        o << ' ' << x;
    }
    o << " }";
    return o;
}

void main_visual() {
    BinTree<int> t;
    int depth;
    while (cin >> t >> depth) {
        cout << values_at_depth(t, depth) << endl;
    }
}

void main_inline() {
    string line;
    while (getline(cin, line)) {
        BinTree<int> t = bintree_inline_read<int>(line);
        getline(cin, line);
        int depth = read_int(line);
        cout << values_at_depth(t, depth) << endl;
    }
}

int main() {
    string line;
    getline(cin, line);
    if (line == "visual") {
        main_visual();
    } else if (line == "inline") {
        main_inline();
    } else {
        assert(false);
    }
}
