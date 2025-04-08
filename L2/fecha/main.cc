// g++ -o fechas main.cc fecha.cc

#include <iostream>
#include <vector>
#include <algorithm>
#include "fecha.hh"
using namespace std;

bool comparacion(Fecha f1, Fecha f2) {
	return f1.menor(f2);
}

int dias_diferencia(Fecha f1, Fecha f2) {
	int dif = 0;
	Fecha ini, fin;

	if (f1.menor(f2) or f1.igual(f2)) {
		ini = f1;
		fin = f2;
	} else {
		ini = f2;
		fin = f1;
	}

	while (not ini.igual(fin)) {
		ini = ini.suma_dias(1);
		++dif;
	}

	return dif;
}

int main() {
	Fecha f(30, 12, 2024);
	cout << "La fecha por defecto: " << f << endl;

	Fecha hoy = Fecha::hoy();
	cout << "Hoy es: " << hoy << endl;

	Fecha en_7_dias = hoy.suma_dias(7);
	cout << "Dentro de una semana será: " << en_7_dias << endl;

	cout << "Todas las fechas hasta fin de mes:" << endl;
	Fecha fin_de_mes(1, hoy.mes() + 1, hoy.anyo());

	Fecha g = hoy;
	while (g.menor(fin_de_mes)) {
		cout << g << ' ';
		g = g.suma_dias(1);
	}
	cout << endl;

    f = f.suma_dias(1);
    cout << f << endl;
    f = f.suma_dias(1);
    cout << f << endl;
    f = f.suma_dias(35);
    cout << f << endl << endl;

	/* vector<Fecha> entrada;
	Fecha fecha;
	int i = 0;
	while (cin >> fecha) entrada.push_back(fecha);
	sort(entrada.begin(), entrada.end(), comparacion);
	for (int i = 0; i < entrada.size(); ++i) cout << entrada[i] << endl; */

	Fecha fecha1, fecha2;
	cin >> fecha1 >> fecha2;
	cout << dias_diferencia(fecha1, fecha2) << endl;
}
