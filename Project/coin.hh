#ifndef COIN_HH
#define COIN_HH

#include <vector>
#include "utils.hh"

/**
 * @class Coin
 * @brief Representa una moneda recollible al joc.
 *
 * La classe Coin defineix la posició i estat d'una moneda que pot ser
 * recollida pel personatge, així com l'animació de renderitzat en tres
 * fotogrames diferents.
 */
class Coin {
 private:
    /**
     * @brief Coordenada X del costat esquerre de la moneda.
     */
    int left_;

    /**
     * @brief Coordenada Y del costat superior de la moneda.
     */
    int top_;

    /**
     * @brief Coordenada X del costat dret de la moneda.
     */
    int right_;

    /**
     * @brief Coordenada Y del costat inferior de la moneda.
     */
    int bottom_;

    /**
     * @brief Estat de recollida de la moneda.
     *
     * Si és cert (`true`), la moneda ja s'ha recollit i no es renderitza ni compta.
     */
    bool taken_ = false;

    /**
     * @brief Textures d'animació de la moneda per fotograma.
     *
     * Conté tres matrius de píxels (`coin_texture_0_`, `coin_texture_1_`,
     * `coin_texture_2_`) que representen els diferents estats de color
     * de la moneda durant l'animació.
     */
    static const std::vector<std::vector<int>> coin_texture_0_;
    static const std::vector<std::vector<int>> coin_texture_1_;
    static const std::vector<std::vector<int>> coin_texture_2_;

 public:
    /**
     * @brief Constructor per defecte.
     *
     * Col·loca la moneda a la posició (0, 0) amb mida de 10×14 píxels.
     */
    Coin() : left_(0), top_(0), right_(10), bottom_(14) {}

    /**
     * @brief Constructor de còpia.
     *
     * Replica la posició i mida d'una altra moneda.
     *
     * @param other Referència a la moneda a copiar.
     */
    Coin(const Coin& other)
        : left_(other.left_), top_(other.top_), 
          right_(other.right_), bottom_(other.bottom_),
          taken_(other.taken_) {}

    /**
     * @brief Constructor a partir d'un punt.
     *
     * Situa la cantonada superior esquerra a `pos` i ajusta la mida a 10×14.
     *
     * @param pos Punt (`pro2::Pt`) amb coordenades x i y.
     */
    Coin(pro2::Pt pos)
        : left_(pos.x), top_(pos.y), right_(pos.x + 10), bottom_(pos.y + 14) {}

    /**
     * @brief Constructor amb coordenades explícites.
     *
     * Idèntic al constructor anterior, però rebent valors enters.
     *
     * @param posx Coordenada X de la cantonada superior esquerra.
     * @param posy Coordenada Y de la cantonada superior esquerra.
     */
    Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 10), bottom_(posy + 14) {}

    /**
     * @brief Dibuixa la moneda a la finestra.
     *
     * Selecciona el fotograma d'animació segons el comptador de frames
     * de la finestra (`frame_count()`), alternant entre les tres textures.
     *
     * @param window Instància de `pro2::Window` on fer el render.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si la moneda ha estat recollida.
     *
     * @return `true` si `taken_` és cert.
     */
    bool is_taken() const;

    /**
     * @brief Marca la moneda com a recollida i incrementa el contador.
     *
     * Només compta la moneda la primera vegada que es recull.
     *
     * @param num_coins_taken Referència al comptador global de monedes.
     */
    void taken(int& num_coins_taken);

    /**
     * @brief Detecta si un punt ha travessat la zona de la moneda.
     *
     * Útil per detectar la col·lisió de recollida des de qualsevol costat.
     *
     * @param pmod Rectangule `pro2::Rect` que ajusta la mida del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si el punt ha creuat el rectangle de la moneda.
     */
    bool has_crossed_coin(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Retorna el rectangle que delimita la moneda.
     *
     * Construeix un `pro2::Rect` amb les coordenades de la moneda.
     *
     * @return Rectangle amb `left`, `top`, `right` i `bottom`.
     */
    pro2::Rect get_rect() const { return {left_, top_, right_, bottom_}; }
};

#endif // COIN_HH