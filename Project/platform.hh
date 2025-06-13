#ifndef PLATFORM_HH
#define PLATFORM_HH

#include <vector>
#include "window.hh"

/**
 * @class Platform
 * @brief Representa una plataforma rectangular en el món del joc.
 *
 * La classe Platform defineix la posició, mida i textura d'una plataforma,
 * i proporciona mètodes per renderitzar-la i detectar col·lisions amb punts.
 */
class Platform {
 private:
    /**
     * @brief Coordenada X del costat esquerre de la plataforma.
     */
    int left_,
    /**
     * @brief Coordenada X del costat dret de la plataforma.
     */
        right_,
    /**
     * @brief Coordenada Y del costat superior de la plataforma.
     */
        top_,
    /**
     * @brief Coordenada Y del costat inferior de la plataforma.
     */
        bottom_;

    /**
     * @brief Textura de la plataforma com a matriu de píxels.
     *
     * Patró estàtic de colors utilitzat per pintar la superfície
     * de la plataforma de manera repetitiva.
     */
    static const std::vector<std::vector<int>> platform_texture_;

 public:
    /**
     * @brief Constructor per defecte.
     *
     * Inicialitza una plataforma buida amb totes les coordenades a zero.
     */
    Platform()
        : left_(0), right_(0), top_(0), bottom_(0) {}

    /**
     * @brief Constructor de còpia.
     *
     * Crea una nova plataforma amb les mateixes coordenades que una altra.
     *
     * @param other Plataforma de la qual copiar les coordenades.
     */
    Platform(const Platform& other)
        : left_(other.left_), right_(other.right_), top_(other.top_), bottom_(other.bottom_) {}

    /**
     * @brief Constructor amb coordenades explícites.
     *
     * Defineix la posició i mida de la plataforma mitjançant les coordenades
     * dels seus costats.
     *
     * @param left   Coordenada X del costat esquerre.
     * @param right  Coordenada X del costat dret.
     * @param top    Coordenada Y del costat superior.
     * @param bottom Coordenada Y del costat inferior.
     */
    Platform(int left, int right, int top, int bottom)
        : left_(left), right_(right), top_(top), bottom_(bottom) {}

    /**
     * @brief Dibuixa la plataforma a la finestra gràfica.
     *
     * Utilitza la textura `platform_texture_` per mapar colors a cada píxel
     * dins de la regió de la plataforma i crida a `window.set_pixel()`.
     *
     * @param window Instància de `pro2::Window` on es realitza el renderitzat.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Detecta si un punt ha creuat el sostre de la plataforma movent-se
     *        cap avall.
     *
     * Útil per implementar la lògica de suport (grounding) quan Mario o altres
     * entitats cauen sobre la plataforma.
     *
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si el punt ha travessat el costat superior de la plataforma.
     */
    bool has_crossed_floor_downwards(pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Comprova si un punt es troba dins de la plataforma.
     *
     * @param pt Punt amb coordenades X i Y.
     * @return `true` si `pt` està contingut en el rectangle de la plataforma.
     */
    bool is_pt_inside(pro2::Pt pt) const;

    /**
     * @brief Retorna la coordenada Y del costat superior.
     * @return Valor de `top_`.
     */
    int top() const { return top_; }

    /**
     * @brief Obté el rectangle que delimita la plataforma.
     *
     * @return `pro2::Rect` amb `left`, `top`, `right` i `bottom`.
     */
    pro2::Rect get_rect() const { return {left_, top_, right_, bottom_}; }
};

#endif // PLATFORM_HH
