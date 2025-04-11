#include "Lavadora.hh"

Lavadora::Lavadora() {
    ini = false;
}

void Lavadora::inicializar(int pmax, bool col) {
    ini = true;
    pesmax = pmax;
    Lavadora::col = col;
    pes = 0;
}

void Lavadora::anadir_prenda(const Prenda& p) {
    if (col == p.consul_color()) {
        prendas.push_back(p);
        pes += p.consul_peso();
    }
}

void Lavadora::lavado() {
    prendas = {};
    ini = false;
}

bool Lavadora::esta_inicializada() const {
    return ini;
}

bool Lavadora::consultar_color() const {
    return col;
}

int Lavadora::consultar_peso() const {
    return pes;
}

int Lavadora::consultar_peso_maximo() const {
    return pesmax;
}

void Lavadora::escribir() const {
    cout << "Lavadora de ";
    if (col) cout << "color";
    else cout << "blanco";
    cout << ", con peso actual " << pes << " y peso maximo " << pesmax << "; sus prendas son" << endl;

    for (auto it = prendas.begin(); it != prendas.end(); ++it) (*it).escribir();
    cout << endl;
}