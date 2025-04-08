#include "CuaIOParInt.hh"
using namespace std;

/**
 * @brief 
 * @param c és buida; el canal estandar d’entrada conté un nombre
 * parell d’enters, acabat pel parell 0 0
 * @return s’han encuat a c els elements llegits fins al 0 0 (no inclòs)
*/
void llegirCuaParInt(queue<ParInt>& c) {
    ParInt p;
    while (cin >> p.user >> p.time and (p.user != 0 or p.time != 0)) c.push(p);
}

/**
 * @brief 
 * @param cert
 * @return s’han escrit al canal estandar de sortida els elements
 * de c
*/
void escriureCuaParInt(queue<ParInt> c) {
    int s = c.size();
    for (int i = 0; i < s; ++i) {
        cout << c.front().user << ' ' << c.front().time << endl;
        c.pop();
    }
}

int canviarCuaParInt(queue<ParInt>& c1, queue<ParInt>& c2) {
    int t = c1.front().time;
    c2.push(c1.front());
    c1.pop();
    return t;
}
