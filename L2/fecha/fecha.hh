#ifndef FECHA_HH
#define FECHA_HH

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Fecha fecha.hh
 * @brief Clase que representa una fecha con día, mes y año.
 *
 * La clase implementa operaciones para crear fechas, sumar días, determinar si dos fechas son
 * iguales, obtener la fecha del sistema, etc.
 */
class Fecha {
    int dia_, mes_, anyo_;

    void _normaliza_dias();
    void _normaliza_meses();

    /**
     * @brief Suma un número de `dias` a la fecha actual.
     * @param dias El número de días a sumar.
     */
    void _suma_dias(int dias);

    /**
     * @brief Suma un número de `meses` a la fecha actual.
     * @param dias El número de meses a sumar.
     */
    void _suma_meses(int meses);

    /**
     * @brief Suma un número de `anyos` a la fecha actual.
     * @param dias El número de años a sumar.
     */
    void _suma_anyos(int anyos) { anyo_ += anyos; }

   public:
    /**
     * @brief Constructor por defecto, inicializa la fecha a 1/1/2000.
     */
    Fecha() : dia_(1), mes_(1), anyo_(2000) {}

    /**
     * @brief Construye una fecha a partir de su dia, mes y año como enteros.
     */
    Fecha(int dia, int mes, int any) : dia_(dia), mes_(mes), anyo_(any) { _normaliza_dias(); }

    /**
     * @brief Constructor de copia: construye una fecha a partir de `otra`, ya existente.
     */
    Fecha(const Fecha& otra) : dia_(otra.dia_), mes_(otra.mes_), anyo_(otra.anyo_) {
        _normaliza_dias();
    }

    /**
     * @brief Calcula una nueva fecha sumando un número de `dias` al objeto.
     * @param dias El número de días a sumar.
     */
    Fecha suma_dias(int dias) const;

    // Los siguientes 3 métodos son inline porque estan definidos directamente
    // en la declaración de la clase.

    /**
     * @brief Devuelve el día de la fecha.
     */
    int dia() const { return dia_; }

    /**
     * @brief Devuelve el mes de la fecha.
     */
    int mes() const { return mes_; }

    /**
     * @brief Devuelve el año de la fecha.
     */
    int anyo() const { return anyo_; }

    // Métodos de comparación

    /**
     * @brief Devuelve `true` si la fecha es anterior a `otra`, `false` en caso contrario.
     */
    bool menor(const Fecha& otra) const;

    /**
     * @brief Devuelve `true` si la fecha es posterior a `otra`, `false` en caso contrario.
     */
    bool mayor(const Fecha& otra) const;

    /**
     * @brief Devuelve `true` si la fecha es igual a `otra`, `false` en caso contrario.
     */
    bool igual(const Fecha& otra) const;

    /**
     * @brief Devuelve la fecha actual (obteniéndola del sistema operativo)
     * @returns Un objeto de clase `Fecha` con la fecha actual.
     */
    static Fecha hoy();

    /**
     * @brief Operador de escritura para fechas.
     * Este operador define el comportamiento de `cout << f;` donde `f`
     * es un objeto de clase `Fecha`.
     *
     * @param in El `stream` de salida (`cout` u otro).
     * @param fecha La fecha a escribir.
     * @return El mismo `istream` de entrada para permitir encadenar entradas.
     *
     * @pre `f` es una fecha válida.
     */
    friend std::istream& operator>>(std::istream& in, Fecha& fecha);

    /**
     * @brief Operador de lectura para fechas.
     * Este operador define el comportamiento de `cin >> f;` donde `f` es un
     * objeto de clase `Fecha`.
     *
     * @param out El `stream` de entrada (`cin` u otro).
     * @param fecha La fecha a leer.
     * @return El mismo `ostream` de salida para permitir encadenar salidas.
     */
    friend std::ostream& operator<<(std::ostream& out, const Fecha& fecha);
};

#endif