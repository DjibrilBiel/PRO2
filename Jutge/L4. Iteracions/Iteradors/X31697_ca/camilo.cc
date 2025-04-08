#include <list>
#include <string>
using namespace std;

void inserta_don(list<string>& texto) {
    for (list<string>::iterator i = texto.begin(); i != texto.end(); ++i) 
        if (*i == "Camilo") texto.insert(i, "Don");
}