#include "CuaIOParInt.hh"
using namespace std;

int main() {
    queue<ParInt> inici;
    llegirCuaParInt(inici);

    queue<ParInt> f1, f2;
    int t1 = 0, t2 = 0;
    while (inici.size() > 0) {
        if (t1 <= t2) t1 += canviarCuaParInt(inici, f1);
        else t2 += canviarCuaParInt(inici, f2);
    }

    escriureCuaParInt(f1);
    cout << endl;
    escriureCuaParInt(f2);
}