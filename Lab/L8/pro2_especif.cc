/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 *
 *
 * En este ejemplo se construye un programa modular que ofrece un menú de opciones para
 * gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y
 * <em>Prenda</em>.
 *
 * Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo de proyecto
 * completamente documentado, incluyendo los elementos privados.
 */

/**
 * @file pro2_s8.cc
 *
 * @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
 */

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Cubeta.hh"
#include "Lavadora.hh"
#include "Prenda.hh"
#ifndef NO_DIAGRAM  // explicado en Prenda.hh
#include "readbool.hh"
#endif

/**
 * @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
 */
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
            l.escribir();
        }
    }
}