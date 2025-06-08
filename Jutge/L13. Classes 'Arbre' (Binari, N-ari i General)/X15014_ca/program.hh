node_arbre* node_arb_sumes(node_arbre* n) const {
    if (n == NULL) return n;

    node_arbre* e = node_arb_sumes(n->segE);
    node_arbre* d = node_arb_sumes(n->segD);

    node_arbre* m = new node_arbre;
    m->segE = e;
    m->segD = d;

    int sum_e = (e == NULL ? 0 : e->info);
    int sum_d = (d == NULL ? 0 : d->info);
    m->info = n->info + sum_e + sum_d;

    return m;
}

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    asum.primer_node = node_arb_sumes(primer_node);
}