#include <ctime>	// time, localtime, tm, ...
#include <fstream>	// Leer y escribir ficheros
#include <iomanip>	// setfill, setw
#include <iostream>
#include <vector>
using namespace std;

#include "fecha.hh"

bool es_bisiesto(int anyo) {
	return (anyo % 4 == 0 && anyo % 100 != 0) || anyo % 400 == 0;
}

int dias_mes(int mes, int anyo) {
	if (mes == 2) {
		return es_bisiesto(anyo) ? 29 : 28;
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		return 30;
	} else {
		return 31;
	}
}

void Fecha::_normaliza_meses() {
	anyo_ += (mes_ - 1) / 12;
    mes_ = (mes_ - 1) % 12 + 1;
}

void Fecha::_normaliza_dias() {
	_normaliza_meses();
	while (dia_ > dias_mes(mes_, anyo_)) {
		dia_ -= dias_mes(mes_, anyo_);
		mes_++;
		_normaliza_meses();
	}
}

void Fecha::_suma_dias(int dias) {
	dia_ += dias;
	_normaliza_dias();
}

void Fecha::_suma_meses(int meses) {
	mes_ += meses;
	_normaliza_meses();
}

Fecha Fecha::suma_dias(int dias) const {
	Fecha f(dia_, mes_, anyo_);	 // Copiamos el objeto actual en uno nuevo
	f._suma_dias(dias);
    return f;
}

bool Fecha::menor(const Fecha& otra) const {
	if (anyo_ != otra.anyo_) {
		return anyo_ < otra.anyo_;
	} else if (mes_ != otra.mes_) {
		return mes_ < otra.mes_;
	} else {
		return dia_ < otra.dia_;
	}
}

bool Fecha::mayor(const Fecha& otra) const {
	if (anyo_ != otra.anyo_) {
		return anyo_ > otra.anyo_;
	} else if (mes_ != otra.mes_) {
		return mes_ > otra.mes_;
	} else {
		return dia_ > otra.dia_;
	}
}

bool Fecha::igual(const Fecha& otra) const {
    return anyo_ == otra.anyo_ && mes_ == otra.mes_ && dia_ == otra.dia_;
}

Fecha Fecha::hoy() {
	time_t t = time(nullptr);
	tm	  *now = localtime(&t);
	return Fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

ostream& operator<<(ostream& out, const Fecha& f) {
	out << setfill('0') << setw(2) << f.dia_;
	out << '/' << setfill('0') << setw(2) << f.mes_;
	out << '/' << setfill('0') << setw(4) << f.anyo_;
	return out;
}

istream& operator>>(istream& in, Fecha& f) {
	char sep;  // Leemos un separador pero no lo usamos
	return in >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
}