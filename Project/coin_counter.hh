#ifndef COIN_COUNTER_HH
#define COIN_COUNTER_HH

#include "window.hh"
#include <vector>

/**
 * @class Coin_Counter
 * @brief Gestiona i mostra el comptador de monedes en la interfície del joc.
 *
 * La classe Coin_Counter proveeix funcions per renderitzar l'icona de moneda
 * i dibuixar el nombre de monedes recollides utilitzant una font pixelada
 * integrada.
 */
class Coin_Counter {
 private:
    static const std::vector<std::vector<int>> coin_texture_;

 public:
    /**
     * @brief Constructor per defecte.
     *
     * No realitza cap inicialització especial, ja que el comptador
     * es basa en paràmetres que es passen a paint_interface().
     */
    Coin_Counter() {}

    /**
     * @brief Dibuixa un dígit individual en la finestra.
     *
     * Escala i posiciona el patró corresponent a `digit` a partir de la
     * font integrada. Cada glif ocupa `font_h`×`font_w` píxels i es col·loca
     * a la posició `(dx, dy)`.
     *
     * @param window Instància de `pro2::Window` on es farà el render.
     * @param digit Nombre entre 0 i 9 que volem mostrar.
     * @param dx Coordenada X de la cantonada superior esquerra del glif.
     * @param dy Coordenada Y de la cantonada superior esquerra del glif.
     * @param font_h Altura en píxels de cada dígit escalat.
     * @param font_w Amplada en píxels de cada dígit escalat.
     */
    void draw_digit(pro2::Window& window,
                    int digit,
                    int dx,
                    int dy,
                    const int font_h,
                    const int font_w);

    /**
     * @brief Pinta la interfície de comptador de monedes.
     *
     * Mostra la icona de moneda, una creu de separació i el valor de
     * `num_coins` en format de dos dígits. El valor es limita a 0–99,
     * descontant 100 si s'excedeix, per a un comptador animat.
     *
     * @param window Instància de `pro2::Window` on es farà el render.
     * @param num_coins Referència al nombre de monedes recollides. Pot ser
     *                   modificat si excedeix 99.
     */
    void paint_interface(pro2::Window& window, int& num_coins);
};


#endif // COIN_COUNTER_HH