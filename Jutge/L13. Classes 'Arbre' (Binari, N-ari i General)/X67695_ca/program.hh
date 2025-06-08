T node_max_suma_cami(node_arbre* n) const {
    if (n == NULL) return 0;

    T left = node_max_suma_cami(n->segE);
    T right = node_max_suma_cami(n->segD);

    if (left > right) return left + n->info;
    return right + n->info;
}

/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const {
    return node_max_suma_cami(primer_node);
}