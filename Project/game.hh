#ifndef GAME_HH
#define GAME_HH

#include "finder.hh"
#include "mario.hh"
#include "platform.hh"
#include "block.hh"
#include "coin.hh"
#include "block_coin.hh"

class Game {
    Mario                   mario_;
    std::vector<Platform>   platforms_;
    std::vector<Block>      blocks_;
    std::vector<Coin>       coins_;
    std::vector<Block_Coin> block_coins_;

    Finder<Platform>   platform_finder_;
    Finder<Block>      block_finder_;
    Finder<Coin>       coin_finder_;
    Finder<Block_Coin> block_coin_finder_;

    int  num_coins_taken_ = 0;
    bool finished_;

    void process_keys(pro2::Window& window);
    void update_objects(pro2::Window& window);
    void update_camera(pro2::Window& window);

 public:
    Game(int width, int height);

    void update(pro2::Window& window);
    void paint(pro2::Window& window);

    bool is_finished() const {
        return finished_;
    }

    int num_coins_taken() {
        return num_coins_taken_;
    }

 private:
    static constexpr int sky_blue = 0x5c94fc;
};

#endif