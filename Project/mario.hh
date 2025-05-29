#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <vector>
#include "platform.hh"
#include "coin.hh"
#include "block.hh"
#include "block_coin.hh"
#include "utils.hh"

class Mario {
 private:
    // Posición de Mario
    pro2::Pt pos_, last_pos_;
    // Velocidad actual (x, y)
    pro2::Pt speed_ = {0, 0};
    // Aceleración actual (x, y)
    pro2::Pt accel_ = {0, 0};
    // Tiempo transcurrido en aceleración
    int      accel_time_ = 0;

    // Indicador si Mario está en el suelo
    bool grounded_ = false;
    // Dirección a la que mira Mario (false = derecha, true = izquierda)
	bool looking_left_ = false;
    // Indicador mario es pequeño (false) o grande (true)
    bool status_mario_ = true;

    /**
     * @brief Aplica la física básica a Mario.
     *
     * Calcula nuevas velocidad y posición según aceleración,
     * gravedad y fricción, y actualiza `grounded_` si corresponder.
     */
	void apply_physics_();
	
 public:
    /**
     * @brief Construye un objeto Mario en la posición indicada.
     *
     * Inicializa la posición actual y la posición anterior de Mario
     * al punto `pos`, sin velocidad ni aceleración.
     *
     * @param pos Coordenadas iniciales de Mario en el mundo.
     */
    Mario(pro2::Pt pos) : pos_(pos), last_pos_(pos) {}

    /**
     * @brief Dibuja a Mario en la ventana gráfica.
     *
     * Renderiza el sprite de Mario (dependiendo de su estado normal o 
     * volteado) en la posición `pos_`, teniendo en cuenta el zoom.
     *
     * @param window Referencia a la ventana donde se pinta a Mario.
     */
    void paint(pro2::Window& window) const;

    /**
     * @brief Obtiene la posición actual de Mario.
     *
     * @returns Un `Pt` con las coordenadas `x` e `y` de Mario.
     */
    pro2::Pt pos() const {
        return pos_;
    }

    /**
     * @brief Establece la coordenada X de la posición de Mario.
     *
     * @param x Nueva coordenada horizontal para Mario.
     */
    void set_x(int x) {
        pos_.x = x;
    }

    /**
     * @brief Establece la coordenada Y de la posición de Mario.
     *
     * @param y Nueva coordenada vertical para Mario.
     */
    void set_y(int y) {
        pos_.y = y;
    }

    /**
     * @brief Comprueba si Mario está en el suelo.
     *
     * @returns `true` si Mario está apoyado en una plataforma o bloque;
     *          `false` si está en el aire.
     */
    bool is_grounded() const {
        return grounded_;
    }

    /**
     * @brief Marca o desmarca a Mario como en el suelo.
     *
     * Si `grounded` es `true`, se resetea la velocidad vertical a cero.
     *
     * @param grounded Nuevo estado de `grounded_`.
     */
    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    /**
     * @brief Alterna el estado de `grounded_` de Mario.
     *
     * Cambia de suelo a aire o viceversa, invocando internamente a `set_grounded`.
     */
    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    /**
     * @brief Hace que Mario realice un salto.
     *
     * Si Mario está en el suelo (`grounded_ == true`), modifica su
     * componente vertical de velocidad para iniciar el salto y 
     * desmarca `grounded_`.
     */
    void jump();

    /**
     * @brief Actualiza la lógica de Mario para el fotograma actual.
     *
     * Aplica física interna (`apply_physics_()`), comprueba colisiones
     * contra plataformas y bloques, recoge monedas de `coins` o
     * `block_coins`, y suma a `num_coins` cuando se recojan.
     *
     * @param window        Referencia a la ventana para leer entrada y cámara.
     * @param platforms     Vector de plataformas del nivel.
     * @param blocks        Vector de bloques sólidos del nivel.
     * @param block_coins   Vector de bloques que contienen monedas.
     * @param coins         Vector de monedas sueltas en el nivel.
     * @param num_coins     Referencia al contador total de monedas recogidas.
     */
    void update(pro2::Window& window, const std::vector<Platform>& platforms, const std::vector<Block>& blocks, vector<Block_Coin>& block_coins, vector<Coin>& coins, int& num_coins);

    pro2::Rect get_rect_modifiers() const {
        if (status_mario_)
            return {-8, 0, 8, 31};
        return {-6, 0, 6, 15};
    }

    pro2::Rect get_rect() const {
        pro2::Rect pos_mod = get_rect_modifiers();
        return {pos_.x + pos_mod.left, pos_.y + pos_mod.top, pos_.x + pos_mod.right, pos_.y + pos_mod.bottom};
    }

 private:
    // Sprites de Mario en estado normal
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_sprite_big_;
};

#endif