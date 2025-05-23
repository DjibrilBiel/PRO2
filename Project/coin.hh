#ifndef COIN_HH
#define COIN_HH

#include <vector>
#include "utils.hh"

/**
 * @class Coin
 *
 * Representa una moneda que el personaje puede recoger.
 */
class Coin {
 private:
    // Coordenadas del borde de la moneda
    int left_, top_, right_, bottom_;

    // Indicador de si la moneda ya ha sido recogida
    bool taken_ = false;

    // Texturas de animación de la moneda
    static const std::vector<std::vector<int>> coin_texture_0_, coin_texture_1_, coin_texture_2_;

 public:
    /**
     * @brief Constructor por defecto.
     *
     * Coloca la moneda en la posición (0,0) con tamaño 10x14.
     */
    Coin() : left_(0), top_(0), right_(10), bottom_(14) {}

    /**
     * @brief Constructor de copia.
     *
     * Duplica posición y tamaño de otra moneda.
     *
     * @param other Moneda a copiar.
     */
    Coin(const Coin& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    /**
     * @brief Construye una moneda en una posición dada.
     *
     * @param pos Coordenadas iniciales de la esquina superior izquierda.
     */
    Coin(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 10), bottom_(pos.y + 14) {} 

    /**
     * @brief Construye una moneda en una posición dada.
     *
     * @param posx Coordenada X de la esquina superior izquierda.
     * @param posy Coordenada Y de la esquina superior izquierda.
     */
    Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 10), bottom_(posy + 14) {}

    /**
     * @brief Dibuja la moneda en la ventana.
     *
     * Selecciona el frame de textura según el estado de animación.
     *
     * @param window Referencia a la ventana gráfica.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si la moneda ha sido recogida.
     *
     * @returns `true` si ya se marcó como tomada.
     */
    bool is_taken() const;

    /**
     * @brief Marca la moneda como tomada y actualiza el contador.
     *
     * @param num_coins_taken Referencia al contador de monedas recogidas.
     */
    void taken(int& num_coins_taken);

    /**
     * @brief Comprueba si un punto ha atravesado la moneda.
     *
     * Útil para detectar colisión de recogida.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si el punto cruzó el rectángulo de la moneda.
     */
    bool has_crossed_coin(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Obtiene el rectángulo que delimita la moneda.
     *
     * @returns Un `pro2::Rect` con `left`, `top`, `right` y `bottom`.
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif