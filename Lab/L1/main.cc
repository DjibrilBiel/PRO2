#include "fecha.hh"

int main() {
	Fecha f = {1, 1, 0};
	fecha_escribir(f);
	std::cout << std::endl;

	f = fecha_actual();
	std::cout << "Hoy es: " << f << std::endl;

	f = fecha_sumar_dias(f, 7);
	std::cout << "Dentro de una semana será: " << f << std::endl;

	std::cout << "Todas las fechas del anyo en curso:" << std::endl;
	f = {1, 1, f.anyo_};
	for (int i = 0; i < 365; i++) {
		std::cout << f << std::endl;
		f = fecha_sumar_dias(f, 1);
	}

    std::vector<Fecha> fechas = leer_fechas_de_fichero("fechas.dat");
    std::cout << fechas.size() << " fechas leídas" << std::endl;

	std::cout << fecha_menor(fechas[1], fechas[0]) << " " << fecha_mayor(fechas[1], fechas[0]) << std::endl;
}