#ifndef BLOCK_COIN_HH
#define BLOCK_COIN_HH

#include "utils.hh"
#include <vector>
using namespace std;

/**
 * @class Block_Coin
 *
 * Representa un bloque que puede liberar una moneda al ser golpeado.
 */
class Block_Coin {
 private:
    //  Coordenadas del borde del bloque
    int left_, top_, right_, bottom_;

    // Indicador de si el bloque ya ha sido golpeado
    bool hit_ = false;
    // Contador para animación o estado de la moneda mostrada
    int show_coin_ = 0;

    /**
     * @brief Texturas para diferentes estados y animaciones:
     * - block_hit_texture_: bloque golpeado
     * - block_texture_: estado normal del bloque
     * - coin_from_block_0..3_: frames de la moneda emergente
     */
    static const vector<vector<int>> block_hit_texture_, block_texture_, coin_from_block_0_,
                                     coin_from_block_1_, coin_from_block_2_, coin_from_block_3_;

 public:
    /**
     * @brief Constructor por defecto.
     *
     * Crea un bloque de 16x16 en (0,0) sin haber sido golpeado.
     */
    Block_Coin() : left_(0), top_(0), right_(16), bottom_(16) {}

    /**
     * @brief Constructor de copia.
     *
     * Duplica posición y estado de otro Block_Coin.
     *
     * @param other Bloque-moneda a copiar.
     */
    Block_Coin(const Block_Coin& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    /**
     * @brief Construye un bloque-moneda en una posición dada.
     *
     * @param pos Coordenadas iniciales de la esquina superior izquierda.
     */
    Block_Coin(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {} 

    /**
     * @brief Construye un bloque-moneda en coordenadas dadas.
     *
     * @param posx Coordenada X de la esquina superior izquierda.
     * @param posy Coordenada Y de la esquina superior izquierda.
     */
    Block_Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    /**
     * @brief Dibuja el bloque-moneda en la ventana.
     *
     * Selecciona textura según si ha sido golpeado.
     *
     * @param window Referencia a la ventana gráfica.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si el bloque ha sido golpeado.
     *
     * @returns `true` si `hit_ == true`.
     */
    bool is_hit() const;

    /**
     * @brief Marca el bloque como golpeado y libera una moneda.
     *
     * Incrementa el contador `num_coins` si es la primera vez.
     *
     * @param num_coins Referencia al contador de monedas.
     */
    void hit(int& num_coins);

    /**
     * @brief Actualiza el estado de la moneda emergente.
     *
     * Controla la animación de aparición de la moneda.
     */
    void update_coin();

    /**
     * @brief Dibuja la moneda emergente si corresponde.
     *
     * @param window Referencia a la ventana gráfica.
     */
    void paint_coin(pro2::Window& window) const;

    /**
     * @brief Devuelve la coordenada X del borde izquierdo.
     *
     * @returns `left_`.
     */
    int left() const {
        return left_;
    }

    /**
     * @brief Devuelve la coordenada Y del borde superior.
     *
     * @returns `top_`.
     */
    int top() const {
        return top_;
    }

    /**
     * @brief Devuelve la coordenada X del borde derecho.
     *
     * @returns `right_`.
     */
    int right() const {
        return right_;
    }

    /**
     * @brief Devuelve la coordenada Y del borde inferior.
     *
     * @returns `bottom_`.
     */
    int bottom() const {
        return bottom_;
    }

    /**
     * @brief Comprueba cruce hacia abajo del bloque.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si el punto cruza el borde superior moviéndose hacia abajo.
     */
    bool has_crossed_block_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce hacia arriba del bloque.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si el punto cruza el borde inferior moviéndose hacia arriba.
     */
    bool has_crossed_block_upwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce de izquierda a derecha.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si cruza el borde izquierdo moviéndose hacia la derecha.
     */
    bool has_crossed_block_left_to_right(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce de derecha a izquierda.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si cruza el borde derecho moviéndose hacia la izquierda.
     */
    bool has_crossed_block_right_to_left(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Obtiene el rectángulo que delimita el bloque-moneda.
     *
     * @returns Un `pro2::Rect` con `left`, `top`, `right` y `bottom`.
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif