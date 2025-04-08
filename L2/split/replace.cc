#include <iostream>
#include <string>
using namespace std;


int main () {
    string s;
    cout << "Añade una string: ";
    getline(cin, s);

    int pos = s.find("trumpet", 0);
    while (pos != -1) {
        s.replace(pos, 7, "[redacted]");
        pos = s.find("trumpet", pos + 10);
    }

    cout << s << endl;
}