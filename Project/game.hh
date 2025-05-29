#ifndef GAME_HH
#define GAME_HH

#include "coin_counter.hh"
#include "finder.hh"
#include "mario.hh"
#include "platform.hh"
#include "block.hh"
#include "coin.hh"
#include "block_coin.hh"

class Game {
    // Personaje principal
    Mario                   mario_;
    // Objetos del nivel
    std::vector<Platform>   platforms_;
    std::vector<Block>      blocks_;
    std::vector<Coin>       coins_;
    std::vector<Block_Coin> block_coins_;

    // Buscadores de colisiones y recogida de objetos
    Finder<Platform>   platform_finder_;
    Finder<Block>      block_finder_;
    Finder<Coin>       coin_finder_;
    Finder<Block_Coin> block_coin_finder_;

    Coin_Counter ccounter_;

    // Contador de monedas recogidas
    int  num_coins_taken_ = 0;
    // Indicador de finalización del juego
    bool finished_;

    /**
     * @brief Procesa la entrada de teclado para el control de Mario.
     *
     * Consulta el estado de las teclas en la ventana y aplica
     * la lógica de movimiento, salto, etc., sobre el objeto `mario_`.
     *
     * @param window Referencia a la ventana gráfica donde se detectan las teclas.
     */
    void process_keys(pro2::Window& window);

    /**
     * @brief Actualiza la lógica de todos los objetos del juego.
     *
     * Recorre plataformas, bloques, monedas y combinaciones bloque-moneda,
     * aplica físicas, colisiones y recoge monedas. Incrementa `num_coins_taken_`
     * cuando corresponda y marca `finished_` si se cumple la condición de fin.
     *
     * @param window Referencia a la ventana para obtener información de cámara o Zoom.
     */
    void update_objects(pro2::Window& window);

    /**
     * @brief Actualiza la posición de la cámara en función de Mario.
     *
     * Centra o desplaza suavemente la cámara para seguir al personaje,
     * ajustando la vista de juego dentro de los límites del mundo.
     *
     * @param window Referencia a la ventana para consultar dimensiones y zoom.
     */
    void update_camera(pro2::Window& window);

 public:
    /**
     * @brief Construye el juego con un área de juego de tamaño dado.
     *
     * Inicializa el nivel, el personaje Mario, los distintos vectores de
     * objetos (plataformas, bloques, monedas…) y los buscadores (Finder).
     *
     * @param width  Ancho en píxels de la ventana/juego.
     * @param height Alto en píxels de la ventana/juego.
     */
    Game(int width, int height);

    /**
     * @brief Actualiza el estado completo del juego por fotograma.
     *
     * Llama internamente a `process_keys()`, `update_objects()` y
     * `update_camera()` para avanzar la simulación una unidad de tiempo.
     *
     * @param window Referencia a la ventana gráfica actual.
     */
    void update(pro2::Window& window);

    /**
     * @brief Pinta en pantalla todos los elementos del juego.
     *
     * Dibuja el escenario, plataformas, bloques, monedas, Mario y la interfaz
     * en la ventana, teniendo en cuenta la posición de la cámara.
     *
     * @param window Referencia a la ventana gráfica donde se renderiza.
     */
    void paint(pro2::Window& window);

    /**
     * @brief Comprueba si el juego ha finalizado.
     *
     * Se marca como terminado cuando se cumple la condición de fin de nivel
     * (por ejemplo, alcanzar la meta o quedarse sin vidas).
     *
     * @returns `true` si el juego está finalizado; `false` en caso contrario.
     */
    bool is_finished() const {
        return finished_;
    }

    /**
     * @brief Devuelve el número de monedas recogidas por Mario.
     *
     * @returns Entero con la cantidad total de monedas que se han tomado hasta ahora.
     */
    int num_coins_taken() {
        return num_coins_taken_;
    }

 private:
    // Color de fondo
    static constexpr int sky_blue = 0x5c94fc;
};

#endif