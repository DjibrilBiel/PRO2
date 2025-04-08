#include "ParInt.hh"
#include "LlistaIOParInt.hh"

int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);

    int n;
    cin >> n;

    int rep = 0, sum = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        ParInt pi = *it;
        if (pi.primer() == n) {
            ++rep;
            sum += pi.segon();
        }
    }

    cout << n << ' ' << rep << ' ' << sum << endl;
}