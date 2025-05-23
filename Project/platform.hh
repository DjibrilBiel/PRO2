#ifndef PLATFORM_HH
#define PLATFORM_HH

#include <vector>
#include "window.hh"

/**
 * @class Platform
 *
 * Representa una plataforma rectangular en el mundo del juego.
 */
class Platform {
 private:
    // Coordenadas del borde de la plataforma
    int left_, right_, top_, bottom_;

    /**
     * @brief Textura de la plataforma en forma de sprite.
     *
     * Contiene patrones de píxeles para el dibujo de la plataforma.
     */
	static const std::vector<std::vector<int>> platform_texture_;

 public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa todos los bordes a cero.
     */
    Platform() : left_(0), right_(0), top_(0), bottom_(0) {}

    /**
     * @brief Constructor de copia.
     *
     * Duplica las coordenadas de otro objeto Platform.
     *
     * @param other Plataforma a copiar.
     */
    Platform(const Platform& other)
        : left_(other.left_), right_(other.right_), top_(other.top_), bottom_(other.bottom_) {}

    /**
     * @brief Construye una plataforma con bordes especificados.
     *
     * @param left   Eje X del borde izquierdo.
     * @param right  Eje X del borde derecho.
     * @param top    Eje Y del borde superior.
     * @param bottom Eje Y del borde inferior.
     */
    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom) {}

    /**
     * @brief Dibuja la plataforma en la ventana.
     *
     * Usa la textura interna `platform_texture_` para renderizar
     * cada bloque de la plataforma.
     *
     * @param window Referencia a la ventana gráfica.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Comprueba si un punto ha cruzado el borde superior de la plataforma
     *        moviéndose hacia abajo.
     *
     * Útil para detectar colisiones "pisando" la plataforma.
     *
     * @param plast Posición anterior del punto.
     * @param pcurr Posición actual del punto.
     * @returns `true` si `plast.y` estaba por encima y `pcurr.y` por debajo del top_.
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprueba si un punto está dentro de la plataforma.
     *
     * @param pt Punto con coordenadas `x`,`y`.
     * @returns `true` si `pt` está en el rectángulo definido por los bordes.
     */
    bool is_pt_inside(pro2::Pt pt) const;

    /**
     * @brief Devuelve la coordenada Y del borde superior.
     *
     * @returns Valor de `top_`.
     */
    int top() const {
        return top_;
    }

    /**
     * @brief Obtiene el rectángulo que ocupa la plataforma.
     *
     * @returns Un `pro2::Rect` con `left`, `top`, `right` y `bottom`.
     */
    pro2::Rect get_rect() const {
        return {left_, top_, right_, bottom_};
    }
};

#endif