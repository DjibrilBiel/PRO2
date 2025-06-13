#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <set>
#include "platform.hh"
#include "coin.hh"
#include "block.hh"
#include "block_coin.hh"
#include "utils.hh"

/**
 * @class Mario
 * @brief Representa el personatge controlat pel jugador (Mario).
 *
 * Gestiona la posició, física, animacions i interaccions de Mario amb
 * plataformes, blocs i monedes dins del nivell.
 */
class Mario {
 private:
    /// Posició actual i posició anterior de Mario.
    pro2::Pt pos_, last_pos_;
    /// Velocitat actual (components x i y).
    pro2::Pt speed_ = {0, 0};
    /// Aceleració temporal per salts o efectes verticals.
    pro2::Pt accel_ = {0, 0};
    /// Comptador de frames per a l'aplicació de l'acceleració.
    int      accel_time_ = 0;

    /// Indicador si Mario està tocat al terra.
    bool grounded_ = false;
    /// Direcció en què mira Mario (false = dreta, true = esquerra).
    bool looking_left_ = false;
    /// Estat de mida de Mario (false = petit, true = gran).
    bool status_mario_ = false;

    /**
     * @brief Aplica la física bàsica (gravetat, acceleració, moviment).
     *
     * Calcula la nova velocitat i posició de Mario segons la gravetat,
     * la fricció i qualsevol acceleració activa, i reinicialitza l'estat
     * de `grounded_` si s'escau.
     */
    void apply_physics_();
	
 public:
    /**
     * @brief Constructor amb posició inicial.
     *
     * Inicialitza Mario a la coordenada `pos`, sense velocitat ni acceleració.
     *
     * @param pos Punt (`pro2::Pt`) amb la posició inicial de Mario.
     */
    Mario(pro2::Pt pos) : pos_(pos), last_pos_(pos) {}

    /**
     * @brief Dibuixa Mario a la finestra gràfica.
     *
     * Renderitza el sprite corresponent segons la mida (petit o gran)
     * i l'orientació (`looking_left_`). Utilitza `paint_sprite()`.
     *
     * @param window Instància de `pro2::Window` per al renderitzat.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Obtén la posició actual de Mario.
     *
     * @return Punt (`pro2::Pt`) amb les coordenades x i y de Mario.
     */
    pro2::Pt pos() const { return pos_; }

    /**
     * @brief Estableix la coordenada X de Mario.
     *
     * @param x Nova coordenada horitzontal.
     */
    void set_x(int x) { pos_.x = x; }

    /**
     * @brief Estableix la coordenada Y de Mario.
     *
     * @param y Nova coordenada vertical.
     */
    void set_y(int y) { pos_.y = y; }

    /**
     * @brief Consulta si Mario està al terra.
     *
     * @return `true` si `grounded_` és cert.
     */
    bool is_grounded() const { return grounded_; }

    /**
     * @brief Marca o desmarca l'estat de terra.
     *
     * Si `grounded` és cert, reinicia la velocitat vertical a zero.
     *
     * @param grounded Nou valor per a `grounded_`.
     */
    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) speed_.y = 0;
    }

    /**
     * @brief Canvia l'estat de `grounded_`.
     *
     * Alterna entre aire i terra, cridant internament `set_grounded()`.
     */
    void toggle_grounded() { set_grounded(!grounded_); }

    /**
     * @brief Fa que Mario salti.
     *
     * Si està al terra, aplica una acceleració vertical negativa
     * i posa `grounded_` a false per iniciar el salt.
     */
    void jump();

    /**
     * @brief Actualitza la lògica de Mario cada fotograma.
     *
     * Aplica física, processa entrades (salt, moviment horitzontal),
     * detecta col·lisions amb plataformes, blocs i blocs-moneda,
     * recull monedes i actualitza el contador `num_coins`.
     *
     * @param window Instància de `pro2::Window` per a entrades i càmera.
     * @param platforms Conjunt de punters a plataformes.
     * @param blocks Conjunt de punters a blocs sòlids.
     * @param block_coins Conjunt de punters a blocs amb moneda.
     * @param coins Conjunt de punters a monedes independents.
     * @param num_coins Referència al comptador global de monedes.
     */
    void update(pro2::Window& window,
                const std::set<Platform*>& platforms,
                std::set<Block*>& blocks,
                std::set<Block_Coin*>& block_coins,
                std::set<Coin*>& coins,
                int& num_coins);

    /**
     * @brief Rectangular modificador segons la mida de Mario.
     *
     * Proporciona offsets per definir la caixa de col·lisió
     * segons si Mario és petit o gran.
     *
     * @return `pro2::Rect` amb els offsets {left, top, right, bottom}.
     */
    pro2::Rect get_rect_modifiers() const {
        return status_mario_ ? pro2::Rect{-8, 0, 8, 31}
                             : pro2::Rect{-6, 0, 6, 15};
    }

    /**
     * @brief Obtén el rectangle de col·lisió de Mario a l'espai món.
     *
     * Combina `pos_` amb els offsets de `get_rect_modifiers()`.
     *
     * @return `pro2::Rect` amb les coordenades absolutes.
     */
    pro2::Rect get_rect() const {
        auto mod = get_rect_modifiers();
        return {pos_.x + mod.left, pos_.y + mod.top,
                pos_.x + mod.right, pos_.y + mod.bottom};
    }

 private:
    /// Sprite de Mario petit.
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    /// Sprite de Mario gran.
    static const std::vector<std::vector<int>> mario_sprite_big_;
};

#endif // MARIO_HH
