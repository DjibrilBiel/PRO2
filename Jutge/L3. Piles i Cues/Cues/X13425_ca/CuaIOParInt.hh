#ifndef FECHA_HH
#define FECHA_HH

#include <iostream>
#include <queue>

struct ParInt {
    int user, time;
};

void llegirCuaParInt(std::queue<ParInt>& c);
// Pre: c és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)

void escriureCuaParInt(std::queue<ParInt> c);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de c

int canviarCuaParInt(std::queue<ParInt>& c1, std::queue<ParInt>& c2);

#endif