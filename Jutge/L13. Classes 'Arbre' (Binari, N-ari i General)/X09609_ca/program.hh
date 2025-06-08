void node_igual(node_arbre* n, const T& x, int i, int& best_i, node_arbre*& m) {
    if (n == NULL) return;
    if (n->info == x and (best_i < 0 or best_i > i)) {
        best_i = i;
        m = n;
    }
    node_igual(n->segE, x, i+1, best_i, m);
    node_igual(n->segD, x, i+1, best_i, m);
}

/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    int i = -1;
    node_arbre* found = NULL;

    node_igual(primer_node, x, 0, i, found);
    if (found != NULL) asub.primer_node = copia_node_arbre(found);
}