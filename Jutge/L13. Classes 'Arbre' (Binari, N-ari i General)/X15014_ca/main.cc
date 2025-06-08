#include "Arbre.hh" 
#include <iostream>
using namespace std;

int main() {
    // 1) Preparem arbres buits per als fills
    Arbre<int> buit;

    // 2) Construïm les fulles:
    //    fulla2  fulla1  fulla3
    Arbre<int> fulla2, fulla1, fulla3;
    fulla2.plantar(2,  buit,    buit);   //   2
    fulla1.plantar(1,  buit,    buit);   //   1
    fulla3.plantar(3,  buit,    buit);   //   3

    // 3) Construïm el subarbre esquerre (arrel = 3, fills 2 i 1):
    //        3
    //       / |
    //      2   1
    Arbre<int> sub_esq;
    sub_esq.plantar(3, fulla2, fulla1);

    // 4) Construïm el subarbre dret de la dreta (arrel = 3, sense fills):
    //      3
    Arbre<int> sub_dret_dret = fulla3;  // ja és exactament una fulla amb 3

    // 5) Construïm el subarbre dret (arrel = 4, fill dret = sub_dret_dret):
    //      4
    //       |
    //        3
    Arbre<int> sub_dret;
    sub_dret.plantar(4, buit, sub_dret_dret);

    // 6) Finalment, plantem l’arrel 2 amb els dos subarbres:
    //         2
    //        / |
    //       3   4
    //      / \   |
    //     2   1   3
    Arbre<int> arbre;
    arbre.plantar(2, sub_esq, sub_dret);

    // --- Ara 'arbre' és l'arbre original ---
    // (pots afegir aquí qualsevol comprovació o recorregut
    // que vulguis imprimir per verificar-lo)

    Arbre<int> arbre_sumes;
    arbre.arb_sumes(arbre_sumes);

    // Ara l’imprimim:
    std::cout << "Arbre original (ASCII):\n";
    arbre.print_ascii();
    cout << endl;
    arbre_sumes.print_ascii();
}