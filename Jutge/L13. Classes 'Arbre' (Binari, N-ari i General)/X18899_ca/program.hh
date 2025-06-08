node_arbreNari* node_arbsuma(node_arbreNari* node) const {
    if (node == NULL) return node;

    T sum = node->info;
    node_arbreNari* new_node = new node_arbreNari;
    for (int i = 0; i < N; ++i) {
        node_arbreNari* child = node_arbsuma(node->seg[i]);
        new_node->seg.push_back(child);
        if (child != NULL) sum += child->info;
    }
    new_node->info = sum;

    return new_node;
}

/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    asum.N = N;
    asum.primer_node = node_arbsuma(primer_node);
}