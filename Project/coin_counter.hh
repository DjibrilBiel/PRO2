#ifndef COIN_COUNTER_HH
#define COIN_COUNTER_HH

#include "window.hh"
#include <vector>

class Coin_Counter {
 private:
    static const std::vector<std::vector<int>> coin_texture_;

 public:
    Coin_Counter() {}

    /**
     * @brief Dibuja un dígito en la ventana usando la fuente interna.
     *
     * Representa el `digit` en pantalla utilizando patrones predefinidos
     * (`digit_font_`), situándolo con su esquina superior izquierda
     * en `(dx, dy)` y usando `font_h` filas por `font_w` columnas.
     *
     * @param digit El número (0–9) que se quiere dibujar.
     * @param dx Coordenada X de destino para el dígito.
     * @param dy Coordenada Y de destino para el dígito.
     * @param font_h Altura en píxeles de cada glifo.
     * @param font_w Anchura en píxeles de cada glifo.
     */
    void draw_digit(pro2::Window& window, int digit, int dx, int dy, const int font_h, const int font_w);

    /**
     * @brief Pinta la interfaz de usuario (por ejemplo, contador de monedas).
     *
     * Dibuja los elementos de la interfaz (texto, iconos, contadores, etc.)
     * en la capa superior de la ventana, basándose en el valor de `num_coins`
     * y actualizando su apariencia.
     *
     * @param num_coins Referencia al número de monedas que se mostrará.
     *                   Puede modificarse para devolver eventos de la UI.
     */
    void paint_interface(pro2::Window& window, int& num_coins);
};


#endif