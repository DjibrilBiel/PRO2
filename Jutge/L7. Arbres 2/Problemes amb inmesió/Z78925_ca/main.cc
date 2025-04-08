#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#include "bintree-io.hh"
#include "bintree.hh"
using namespace pro2;

/**
 * @brief Avalua una expressió binària amb variables
 *
 * L'expressió és sobre els naturals i els operadors `+`, `-`, i `*`.
 * A més, hi ha un diccionari `env` que emmagatzema els valors d'un
 * conjunt de variables que poden aparèixer a l'arbre.
 *
 * @pre `t` és no buit. Totes les variables que apareixen a `t`
 *       estan definides a `env`. Les opercions expressades per
 *       l'arbre no produeixen errors d'_overflow_
 * 
 * @param t Arbre amb l'expressió binària.
 * @param env Diccionari amb parelles (nom de variable, valor). Aquest 
 *            diccionari no es pot modificar.
 */
int tree_eval_env(BinTree<string> t, const map<string, int>& env);

map<string, int> read_env(istream& in) {
    map<string, int> env;
    string name;
    int value;
    while (in >> name && name != ".") {
        in >> value;
        env[name] = value;
    }
    return env;
}

int main() {
    BinTree<string> t;
    while (cin >> t) {
        assert(!t.empty());
        auto env = read_env(cin);
        cout << tree_eval_env(t, env) << endl;
    }
}