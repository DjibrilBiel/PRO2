#ifndef FECHA_HH
#define FECHA_HH

#include <iostream> // que a su vez incluye `string`
#include <vector>
#include <iomanip>	// setfill, setw

struct Fecha {
	int dia_, mes_, anyo_;
};

Fecha fecha_leer();

void fecha_escribir(const Fecha& f);

bool es_bisiesto(int anyo);

int dias_mes(int mes, int anyo);

Fecha fecha_sumar_dias(const Fecha& f, int dias);

/**
 * @brief Operador de escritura para fechas.
 *
 * Este operador define el comportamiento de `cout << f;` donde `f` es una fecha.
 *
 * @param o El `stream` de salida (`cout` u otro).
 * @param f La fecha a escribir.
 *
 * @return El mismo `stream` de salida para permitir encadenar salidas.
 *
 * @pre `f` es una fecha válida.
 */
inline std::ostream& operator<<(std::ostream& out, const Fecha& f) {
	out << std::setfill('0') << std::setw(2) << f.dia_;
	out << '/' << std::setfill('0') << std::setw(2) << f.mes_;
	out << '/' << std::setfill('0') << std::setw(4) << f.anyo_;
	return out;
}

/**
 * @brief Operador de lectura para fechas.
 *
 * Este operador define el comportamiento de `cin >> f;` donde `f` es una fecha.
 *
 * @param in El `stream` de entrada (`cin` u otro).
 * @param f La fecha a leer.
 */
inline std::istream& operator>>(std::istream& in, Fecha& f) {
	char sep;  // Leemos el separador pero no se usa
	in >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
	return in;
}

bool fecha_menor(const Fecha& a, const Fecha& b);

bool fecha_mayor(const Fecha& a, const Fecha& b);

Fecha fecha_actual();

std::vector<Fecha> leer_fechas_de_fichero(const std::string& filename);

#endif