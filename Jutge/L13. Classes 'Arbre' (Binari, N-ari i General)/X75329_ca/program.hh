int node_freq(node_arbre* branch, const T& x) const {
    if (branch == NULL) return 0;

    int result = (branch->info == x ? 1 : 0);

    result += node_freq(branch->segE, x);
    result += node_freq(branch->segD, x);

    return result;
}

/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
    return node_freq(primer_node, x);
}