#ifndef BLOCK_HH
#define BLOCK_HH

#include "utils.hh"
#include <vector>

/**
 * @class Block
 * @brief Representa un bloc sòlid en el món del joc.
 *
 * La classe Block defineix la posició, mida i estat (trencat o no) d'un bloc
 * i proporciona mecanismes per dibuixar-lo i detectar col·lisions amb punts en moviment.
 */
class Block {
 private:
    /**
     * @brief Coordenada X del costat esquerre del bloc.
     */
    int left_;

    /**
     * @brief Coordenada Y del costat superior del bloc.
     */
    int top_;

    /**
     * @brief Coordenada X del costat dret del bloc.
     */
    int right_;

    /**
     * @brief Coordenada Y del costat inferior del bloc.
     */
    int bottom_;

    /**
     * @brief Estat de trencament del bloc.
     *
     * Si és vertader (`true`), el bloc s'ha trencat i deixarà de ser renderitzat o interactiu.
     */
    bool broken_ = false;

    /**
     * @brief Textura del bloc com a matriu de colors.
     *
     * Capa estàtica que defineix el patró de píxels que s'utilitza per pintar cada
     * bloc (16×16 píxels) amb codis de color.
     */
    static const std::vector<std::vector<int>> block_texture_;

 public:
    /**
     * @brief Constructor per defecte.
     *
     * Inicialitza un bloc de 16×16 píxels situat a la posició (0, 0).
     */
    Block()
        : left_(0), top_(0), right_(16), bottom_(16) {}

    /**
     * @brief Constructor de còpia.
     *
     * Crea un nou bloc amb la mateixa posició i mida que un altre existents.
     *
     * @param other Referència al bloc a copiar.
     */
    Block(const Block& other)
        : left_(other.left_), top_(other.top_), right_(other.right_), bottom_(other.bottom_), broken_(other.broken_) {}

    /**
     * @brief Constructor a partir d'un punt.
     *
     * Col·loca la cantonada superior esquerra del bloc a la posició indicada i
     * estableix la mida estàndard de 16×16 píxels.
     *
     * @param pos Punt (`pro2::Pt`) amb coordenades x i y de la nova posició.
     */
    Block(pro2::Pt pos)
        : left_(pos.x), top_(pos.y), right_(pos.x + 16), bottom_(pos.y + 16) {}

    /**
     * @brief Constructor amb coordenades explícites.
     *
     * Similar al constructor anterior, però rebent valors enters per a x i y.
     *
     * @param posx Coordenada X de la cantonada superior esquerra.
     * @param posy Coordenada Y de la cantonada superior esquerra.
     */
    Block(int posx, int posy)
        : left_(posx), top_(posy), right_(posx + 16), bottom_(posy + 16) {}

    /**
     * @brief Dibuixa el bloc a la finestra gràfica.
     *
     * Utilitza la textura `block_texture_` per mapar colors a cada píxel
     * dins de la regió del bloc i crida a `window.set_pixel`.
     *
     * @param window Instància de `pro2::Window` on es realitza el render.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Consulta si el bloc està trencat.
     *
     * @return `true` si el bloc ha estat marcat com a trencat.
     */
    bool is_broken() const;

    /**
     * @brief Marca el bloc com a trencat.
     *
     * Un cop trencat, el bloc pot deixar de reaccionar a col·lisions o ser dibuixat.
     */
    void broken();

    /**
     * @brief Obtén la coordenada X del costat esquerre.
     * @return Valor de `left_`.
     */
    int left() const { return left_; }

    /**
     * @brief Obtén la coordenada Y del costat superior.
     * @return Valor de `top_`.
     */
    int top() const { return top_; }

    /**
     * @brief Obtén la coordenada X del costat dret.
     * @return Valor de `right_`.
     */
    int right() const { return right_; }

    /**
     * @brief Obtén la coordenada Y del costat inferior.
     * @return Valor de `bottom_`.
     */
    int bottom() const { return bottom_; }

    /**
     * @brief Detecta cruïlla descendint d'un punt amb el bloc.
     *
     * Retorna cert si un punt, modificat pel rectangle `pmod`, ha creuat
     * el costat superior del bloc mentre es mou cap avall.
     *
     * @param pmod Rectangule `pro2::Rect` que ajusta la mida del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si hi ha intersecció descendint.
     */
    bool has_crossed_block_downwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla ascendint d'un punt amb el bloc.
     *
     * Retorna cert si un punt ha creuat el costat inferior del bloc movent-se
     * cap amunt, tenint en compte `pmod`.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si hi ha intersecció ascendint.
     */
    bool has_crossed_block_upwards(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla horitzontal d'esquerra a dreta.
     *
     * Retorna cert si el punt travessa el costat esquerre del bloc movent-se
     * cap a la dreta.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si hi ha intersecció esquerra→dreta.
     */
    bool has_crossed_block_left_to_right(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Detecta cruïlla horitzontal de dreta a esquerra.
     *
     * Retorna cert si el punt travessa el costat dret del bloc movent-se
     * cap a l'esquerra.
     *
     * @param pmod Rectangule de modificació del punt.
     * @param plast Posició anterior del punt.
     * @param pcurr Posició actual del punt.
     * @return `true` si hi ha intersecció dreta→esquerra.
     */
    bool has_crossed_block_right_to_left(pro2::Rect pmod, pro2::Pt plast, pro2::Pt pcurr) const;

    /**
     * @brief Retorna el rectangle que delimita el bloc.
     *
     * Construeix un `pro2::Rect` amb les coordenades del bloc.
     *
     * @return Rectanlge amb `left`, `top`, `right` i `bottom`.
     */
    pro2::Rect get_rect() const { return {left_, top_, right_, bottom_}; }
};

#endif // BLOCK_HH
