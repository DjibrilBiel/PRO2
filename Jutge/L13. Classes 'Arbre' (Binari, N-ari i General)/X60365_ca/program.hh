bool node_buscar(node_arbreGen* n, const T& x) const {
    if (n == NULL) return false;
    if (n->info == x) return true;

    bool found = false;
    int i = 0;
    while (i < (n->seg).size() and not found) {
        found = node_buscar(n->seg[i], x);
        ++i;
    }

    return found;
}

/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    return node_buscar(primer_node, x);
}