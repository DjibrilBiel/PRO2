#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Llibre {
    string titol;
    int categoria;
};

int main() {
    int n;
    cin >> n;
    vector< stack<string> > v(n + 1);

    int opcio;
    while (cin >> opcio and opcio != -4) {
        Llibre l; 
        if (opcio == -1) {
            cin >> l.titol >> l.categoria;
            v[l.categoria - 1].push(l.titol);
        } else if (opcio == -2) {
            int quantitat;
            cin >> quantitat >> l.categoria;
            for (int i = 0; i < quantitat; ++i) v[l.categoria - 1].pop();
        } else {
            cin >> l.categoria;
            int size = v[l.categoria - 1].size();
            cout << "Pila de la categoria " << l.categoria << endl;
            for (int  i = 0; i < size; ++i) {
                cout << v[l.categoria - 1].top() << endl;
                v[n].push(v[l.categoria - 1].top());
                v[l.categoria - 1].pop();
            }
            for (int i =  0; i < size; ++i) {
                v[l.categoria - 1].push(v[n].top());
                v[n].pop();
            }
            cout << endl;
        }
    }
}
