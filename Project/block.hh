#ifndef BLOCK_HH
#define BLOCK_HH

#include "utils.hh"
#include <vector>

/**
 * @class Block
 *
 * Representa un bloque sólido en el mundo del juego.
 */
class Block {
 private:
    // Coordenadas del borde del blocque
    int left_, top_, right_, bottom_;

    // Identifica si el bloque ha sido roto
    bool broken_ = false;

    // Textura del bloque
    static const std::vector<std::vector<int>> block_texture_;

 public:
    /**
     * @brief Constructor por defecto.
     *
     * Crea un bloque de 16x16 en (0,0).
     */
    Block() : left_(0), top_(0), right_(16), bottom_(16) {}

    /**
     * @brief Constructor de copia.
     *
     * Duplica posición y tamaño de otro bloque.
     *
     * @param other Bloque a copiar.
     */
    Block(const Block& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_) {}

    /**
     * @brief Construye un bloque en una posición dada.
     *
     * @param pos Coordenadas iniciales de la esquina superior izquierda.
     */
    Block(pro2::Pt pos) : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {} 

    /**
     * @brief Construye un bloque en coordenadas dadas.
     *
     * @param posx Coordenada X de la esquina superior izquierda.
     * @param posy Coordenada Y de la esquina superior izquierda.
     */ 
    Block(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    /**
     * @brief Dibuja el bloque en la ventana.
     *
     * Utiliza `block_texture_` para renderizar el sprite.
     *
     * @param window Referencia a la ventana gráfica.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si el bloque está roto.
     *
     * @returns `true` si `broken_ == true`.
     */
    bool is_broken() const;

    void broken();

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
    bool has_crossed_block_downwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce hacia arriba del bloque.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si el punto cruza el borde inferior moviéndose hacia arriba.
     */
    bool has_crossed_block_upwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce de izquierda a derecha.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si cruza el borde izquierdo moviéndose hacia la derecha.
     */
    bool has_crossed_block_left_to_right(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba cruce de derecha a izquierda.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si cruza el borde derecho moviéndose hacia la izquierda.
     */
    bool has_crossed_block_right_to_left(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Obtiene el rectángulo que delimita el bloque.
     *
     * @returns Un `pro2::Rect` con `left`, `top`, `right` y `bottom`.
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif