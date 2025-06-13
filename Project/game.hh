#ifndef GAME_HH
#define GAME_HH

#include "coin_counter.hh"
#include "finder.hh"
#include "mario.hh"
#include "platform.hh"
#include "block.hh"
#include "coin.hh"
#include "block_coin.hh"

/**
 * @class Game
 * @brief Controla la lògica principal del joc i el seu renderitzat.
 *
 * La classe Game gestiona el personatge principal (Mario), els objectes
 * del nivell (plataformes, blocs, monedes i blocs amb monedes),
 * els cercadors espacials (Finder) per a detecció de col·lisions i ratjos
 * de recollida, el comptador de monedes i l'estat de finalització del joc.
 */
class Game {
 private:
    /**
     * @brief Personatge principal controllat pel jugador.
     */
    Mario                   mario_;
    
    /**
     * @brief Vector de plataformes del nivell.
     */
    std::vector<Platform>   platforms_;

    /**
     * @brief Vector de blocs trencables del nivell.
     */
    std::vector<Block>      blocks_;

    /**
     * @brief Vector de monedes recollibles independents.
     */
    std::vector<Coin>       coins_;

    /**
     * @brief Vector de blocs que alliberen una moneda en ser colpejats.
     */
    std::vector<Block_Coin> block_coins_;

    /**
     * @brief Cercadors espacials per a detecció de col·lisions i recollida.
     *
     * Cada Finder indexa els objectes corresponents en una graella per
     * fer consultes ràpides d'intersecció amb el rectangle de visió.
     */
    Finder<Platform>   platform_finder_;
    Finder<Block>      block_finder_;
    Finder<Coin>       coin_finder_;
    Finder<Block_Coin> block_coin_finder_;

    /**
     * @brief Comptador i icona de monedes recollides.
     */
    Coin_Counter ccounter_;

    /**
     * @brief Quantitat de monedes que ha recollit el jugador fins ara.
     */
    int  num_coins_taken_ = 0;

    /**
     * @brief Indicador d'estat de finalització del joc.
     */
    bool finished_;

    /**
     * @brief Processa l'entrada de teclat per controlar Mario.
     *
     * Llegeix l'estat de les tecles de la finestra i executa la
     * lògica de moviment, salts o sortir del joc.
     *
     * @param window Instància de `pro2::Window` que proveeix l'entrada.
     */
    void process_keys(pro2::Window& window);

    /**
     * @brief Actualitza la lògica de tots els objectes per fotograma.
     *
     * Recupera els objectes visibles via Finder, aplica física,
     * gestiona col·lisions i recollida de monedes, i actualitza
     * l'estat de blocs i monedes animades.
     *
     * @param window Instància de `pro2::Window` per accedir a càmera i temps.
     */
    void update_objects(pro2::Window& window);

    /**
     * @brief Mou la càmera per seguir Mario dins els límits del món.
     *
     * Calcula desplaçaments suau per mantenir Mario dins d'una zona
     * central del viewport i actualitza la posició de la càmera.
     *
     * @param window Instància de `pro2::Window` per modificar la càmera.
     */
    void update_camera(pro2::Window& window);

 public:
    /**
     * @brief Crea una instància del joc amb la mida de finestra especificada.
     *
     * Inicialitza Mario, carrega vectors d'objectes i indexa
     * cada objecte al seu Finder corresponent.
     *
     * @param width Amplada de la finestra/joc en píxels.
     * @param height Alçada de la finestra/joc en píxels.
     */
    Game(int width, int height);

    /**
     * @brief Avança l'estat del joc un fotograma.
     *
     * Invoca process_keys(), update_objects() i update_camera() per
     * fer progressar la simulació i resposta a l'entrada.
     *
     * @param window Instància de `pro2::Window` actual.
     */
    void update(pro2::Window& window);

    /**
     * @brief Dibuixa tots els elements del joc a la finestra.
     *
     * Renderitza fons, plataformes, blocs, monedes, Mario i
     * la interfície (comptador) respectant la posició de la càmera.
     *
     * @param window Instància de `pro2::Window` per al renderitzat.
     */
    void paint(pro2::Window& window);

    /**
     * @brief Indica si el joc ha finalitzat.
     *
     * @return `true` si s'ha activat l'estat de finalització (`finished_`).
     */
    bool is_finished() const { return finished_; }

    /**
     * @brief Retorna el nombre de monedes recollides.
     *
     * @return Enter amb el total de monedes preses pel jugador.
     */
    int num_coins_taken() const { return num_coins_taken_; }

 private:
    /**
     * @brief Color de fons del joc.
     */
    static constexpr int sky_blue = 0x5c94fc;
};

#endif // GAME_HH
