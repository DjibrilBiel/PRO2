#ifndef BLOCK_COIN_HH
#define BLOCK_COIN_HH

#include "utils.hh"
#include <vector>

/**
 * @class Block_Coin
 * @brief Representa un bloc que allibera una moneda en ser colpejat.
 *
 * La classe Block_Coin hereta el comportament bàsic de col·lisió i renderitzat
 * dels blocs i hi afegeix un estat intern per gestionar l'alliberament i
 * animació d'una moneda quan es colpeja per primera vegada.
 */
class Block_Coin {
 private:
    /**
     * @brief Coordenada del bloc.
     */
    int left_, top_, right_, bottom_;

    /**
     * @brief Indica si el bloc ja ha estat colpejat.
     *
     * Un cop colpejat, no alliberarà més monedes.
     */
    bool hit_ = false;

    /**
     * @brief Comptador per a l'animació de la moneda.
     *
     * Controla la durada i estat de l'animació un cop el bloc ha estat colpejat.
     */
    int show_coin_ = 0;

    /**
     * @brief Textures estàtiques per al render del bloc i la moneda.
     *
     * - block_texture_: textura estàndard del bloc.
     * - block_hit_texture_: textura quan el bloc és colpejat.
     * - coin_from_block_0_..coin_from_block_3_: fotogrames de l'animació de la moneda.
     */
    static const std::vector<std::vector<int>> block_texture_;
    static const std::vector<std::vector<int>> block_hit_texture_;
    static const std::vector<std::vector<int>> coin_from_block_0_;
    static const std::vector<std::vector<int>> coin_from_block_1_;
    static const std::vector<std::vector<int>> coin_from_block_2_;
    static const std::vector<std::vector<int>> coin_from_block_3_;

 public:
    /**
     * @brief Constructor per defecte.
     *
     * Inicialitza un bloc de 16×16 píxels a la posició (0, 0) sense haver estat
     * colpejat.
     */
    Block_Coin()
        : left_(0), top_(0), right_(16), bottom_(16) {}

    /**
     * @brief Constructor de còpia.
     *
     * Replica posició i estat d'un altre bloc-moneda.
     *
     * @param other Referència al Block_Coin a copiar.
     */
    Block_Coin(const Block_Coin& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_),
          hit_(other.hit_), show_coin_(other.show_coin_) {}

    /**
     * @brief Constructor a partir d'un punt.
     *
     * Col·loca la cantonada superior esquerra a `pos` i estableix la mida estàndard.
     *
     * @param pos Punt (`pro2::Pt`) amb coordenades x i y de la cantonada.
     */
    Block_Coin(pro2::Pt pos)
        : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {}

    /**
     * @brief Constructor amb coordenades explícites.
     *
     * Similar al constructor anterior, amb valors enters.
     *
     * @param posx Coordenada X de la cantonada superior esquerra.
     * @param posy Coordenada Y de la cantonada superior esquerra.
     */
    Block_Coin(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    /**
     * @brief Dibuixa el bloc-moneda a la finestra gràfica.
     *
     * Selecciona entre la textura normal o la de bloc colpejat segons
     * l'estat `hit_`.
     *
     * @param window Instància de `pro2::Window` per al render.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si el bloc ha estat colpejat.
     * @return `true` si `hit_` és cert.
     */
    bool is_hit() const;

    /**
     * @brief Colpeja el bloc i allibera una moneda.
     *
     * Marca `hit_` i incrementa el comptador de monedes només la primera vegada
     * que es colpeja.
     *
     * @param num_coins Referència al comptador global de monedes.
     */
    void hit(int& num_coins);

    /**
     * @brief Actualitza l'estat de l'animació de la moneda.
     *
     * Disminueix `show_coin_` fins arribar a zero.
     */
    void update_coin();

    /**
     * @brief Dibuixa la moneda emergent si és necessari.
     *
     * Mostra l'animació de frames i posiciona la moneda per sobre del bloc.
     *
     * @param window Instància de `pro2::Window` per al render de la moneda.
     */
    void paint_coin(pro2::Window& window) const;

    /**
     * @brief Obté la coordenada X del costat esquerre.
     * @return Valor de `left_`.
     */
    int left() const { return left_; }

    /**
     * @brief Obté la coordenada Y del costat superior.
     * @return Valor de `top_`.
     */
    int top() const { return top_; }

    /**
     * @brief Obté la coordenada X del costat dret.
     * @return Valor de `right_`.
     */
    int right() const { return right_; }

    /**
     * @brief Obté la coordenada Y del costat inferior.
     * @return Valor de `bottom_`.
     */
    int bottom() const { return bottom_; }

    /**
     * @brief Detecta cruïlla descendint d'un punt amb el bloc.
     *
     * @param pmod Rectangule `pro2::Rect` que ajusta la mida del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si el punt travessa el costat superior movent-se cap avall.
     */
    bool has_crossed_block_downwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla ascendint d'un punt amb el bloc.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si el punt travessa el costat inferior movent-se cap amunt.
     */
    bool has_crossed_block_upwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla horitzontal d'esquerra a dreta.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si travessa el costat esquerre movent-se cap a la dreta.
     */
    bool has_crossed_block_left_to_right(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla horitzontal de dreta a esquerra.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si travessa el costat dret movent-se cap a l'esquerra.
     */
    bool has_crossed_block_right_to_left(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Retorna el rectangle que delimita el bloc.
     * @return `pro2::Rect` amb `left`, `top`, `right` i `bottom`.
     */
    pro2::Rect get_rect() const { return {left_, top_, right_, bottom_}; }
};

#endif // BLOCK_COIN_HH
