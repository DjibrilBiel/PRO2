#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @fn vector<string> split(string text, string sep)
 *
 * @brief Divide un texto en partes separadas por un separador.
 *
 * Ejemplo: `split("1,2,3", ",")` devuelve `{"1", "2", "3"}`
 *
 * @param text Texto a dividir
 * @param sep Separador
 *
 * @pre: `sep.length() >= 0`. Si `sep` está vacío, se divide cada carácter.
 *
 * @return `vector<string>` Partes del texto
 */
vector<string> split(string text, string sep) {
    vector<string> pieces;

    int start = 0;  // como si hubiera un separador antes del inicio
    int pos = text.find(sep, start);
    while (pos < text.length() && pos != -1) {
        int    tam = sep.empty() ? 1 : pos - start;
        string piece = text.substr(start, tam);

        pieces.push_back(piece);

        start = pos + (sep.empty() ? 1 : sep.length());
        pos = text.find(sep, start);
    }
    if (start < text.length()) {
        pieces.push_back(text.substr(start));
    }
    return pieces;
}

string join(vector<string> pieces, string sep) {
    string res;
    if (pieces.size() == 0) return res;
    res = pieces[0];

    for (int i = 1; i < pieces.size(); ++i) res += sep + pieces[i];
    return res;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{";
    if (!v.empty()) {
        out << v[0];
        for (int i = 1; i < v.size(); i++) {
            out << ", " << v[i];
        }
    }
    return out << "}";
}

int main() {
    cout << split("12345", "") << endl;
    cout << split("1,2,3", ",") << endl;
    cout << split("axxbxxc", "xx") << endl;
    cout << split("Name;Age;ID;Comment", ";") << endl;
    cout << split("/usr/sbin:/usr/bin:/sbin:/bin", ":") << endl;
    cout << split("x; y; z; t", "; ") << endl;
    cout << split("", "") << endl;
    cout << split("", ",,") << endl;
    cout << join(split("12345", ""), "") << endl;
    cout << join(split("1,2,3", ","), ",") << endl;
}