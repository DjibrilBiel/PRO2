#include "Lavadora.hh"
#include "Cubeta.hh"
#include "Prenda.hh"

int main() {
    Lavadora l;
    Cubeta c;
    int peso;
    string color;

    string ins;
    while (cin >> ins and ins != "-8") {
        if (ins == "-1") {
            cin >> peso >> color;
            bool b;
            if (color == "true") b = true;
            else b = false;
            l.inicializar(peso, b);
        } else if (ins == "-2") {
            cin >> peso >> color;
            if (l.esta_inicializada()) {
                bool b;
                if (color == "true") b = true;
                else b = false;
                Prenda p(peso, b);
                l.anadir_prenda(p);
            }
        } else if (ins == "-3") {
            cin >> peso >> color;
            bool b;
            if (color == "true") b = true;
            else b = false;
            Prenda p(peso, b);
            c.anadir_prenda(p);
        } else if (ins == "-4") {
            if (l.esta_inicializada()) 
                c.completar_lavadora(l);
        } else if (ins == "-5")
            l.lavado();
        else if (ins == "-6") {
            cout << "   Cubeta: " << endl;
            c.escribir();
        } else {
            cout << "   Lavadora: " << endl;
            if (l.esta_inicializada()) l.escribir();
            else cout << "Lavadora no inicializada" << endl << endl;
        }
    }
}